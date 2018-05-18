// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "PlayerPawn.h"
#include "GameCameraActor.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"
#include "PauseMenuWidget.h"
#include "Components/Button.h"

AMainGamePlayerController::AMainGamePlayerController()
	: Super()
{
	static ConstructorHelpers::FClassFinder<UPauseMenuWidget> PauseMenuClass(TEXT("/Game/WBP_PauseMenu"));
	if (PauseMenuClass.Succeeded())
	{
		PauseMenuWidgetClass = PauseMenuClass.Class;
	}
}

void AMainGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.f));
	InputComponent->BindAxis("Player_MovePitch", this, &AMainGamePlayerController::AddPitchInput);

	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &AMainGamePlayerController::Fire);

	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Pause", EKeys::P));
	InputComponent->BindAction("Player_Pause", IE_Pressed, this, &AMainGamePlayerController::OnPauseMenu);
}

void AMainGamePlayerController::AddPitchInput(float val)
{
	Super::AddPitchInput(val);
	APlayerPawn* PossesedPawn = Cast<APlayerPawn>(GetPawn());
	if (PossesedPawn != nullptr)
	{
		PossesedPawn->MouseMovePitchInput(val);
	}
}

void AMainGamePlayerController::Fire()
{
	APlayerPawn* PossessedPawn = Cast<APlayerPawn>(GetPawn());
	if (PossessedPawn != nullptr)
	{
		PossessedPawn->Fire();
	}
}

void AMainGamePlayerController::BeginPlay()
{
	TArray<AActor*> FindedActors;
	UGameplayStatics::GetAllActorsOfClass(this, AGameCameraActor::StaticClass(), FindedActors);

	for (AActor* Actor : FindedActors)
	{
		AGameCameraActor* Camera = Cast<AGameCameraActor>(Actor);
		if (Camera != nullptr)
		{
			GameCameras.Add(Camera);
		}
	}

	if (PauseMenuWidgetClass != nullptr)
	{
		PauseMenuWidget = CreateWidget<UPauseMenuWidget>(this, PauseMenuWidgetClass);
	}

	PauseMenuWidget->GoToTitleButton->OnClicked.AddDynamic(this, &AMainGamePlayerController::OnPauseMenuGotoTitleButton);
	PauseMenuWidget->CloseMenuButton->OnClicked.AddDynamic(this, &AMainGamePlayerController::OnPauseMenuCloseButton);

	Super::BeginPlay();
}

AGameCameraActor* AMainGamePlayerController::ChangeGameCamera(const FName& Tag)
{
	for (AGameCameraActor* Camera : GameCameras)
	{
		if (Camera != nullptr)
		{
			if (Camera->ActorHasTag(Tag))
			{
				SetViewTargetWithBlend(Cast<AActor>(Camera));
				return Camera;
			}
		}
	}
	return Cast<AGameCameraActor> (GetViewTarget());
}

void AMainGamePlayerController::OnPauseMenu()
{
	if (PauseMenuWidget != nullptr)
	{
		if (!PauseMenuWidget->IsInViewport())
		{
			PauseMenuWidget->AddToViewport();

			SetInputMode(FInputModeUIOnly().SetLockMouseToViewportBehavior(EMouseLockMode::LockOnCapture).SetWidgetToFocus(PauseMenuWidget->TakeWidget()));
			bShowMouseCursor = true;
		}
	}
	SetPause(true);
}

void AMainGamePlayerController::OnPauseMenuGotoTitleButton()
{
	if (PauseMenuWidget != nullptr)
	{
		PauseMenuWidget->CloseMenu();

		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = true;

		SetPause(false);
		UGameplayStatics::OpenLevel(this, TEXT("/Game/GameTitle"));
	}
}

void AMainGamePlayerController::OnPauseMenuCloseButton()
{
	if (PauseMenuWidget != nullptr)
	{
		PauseMenuWidget->CloseMenu();

		SetInputMode(FInputModeGameOnly());
		bShowMouseCursor = false;
	}
	SetPause(false);
}