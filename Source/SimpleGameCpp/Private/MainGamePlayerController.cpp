// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGamePlayerController.h"
#include "Components/InputComponent.h"
#include "GameFramework/InputSettings.h"
#include "PlayerPawn.h"

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
