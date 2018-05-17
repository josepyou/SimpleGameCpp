// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "PlayerPawn.h"
#include "GameCameraActor.h"
#include "Kismet/GameplayStatics.h"

void AMainGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.f));
	InputComponent->BindAxis("Player_MovePitch", this, &AMainGamePlayerController::AddPitchInput);

	GetMutableDefault<UInputSettings>()->AddActionMapping(FInputActionKeyMapping("Player_Fire", EKeys::LeftMouseButton));
	InputComponent->BindAction("Player_Fire", IE_Pressed, this, &AMainGamePlayerController::Fire);
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