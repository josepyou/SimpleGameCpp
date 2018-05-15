// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGamePlayerController.h"
#include "GameFramework/InputSettings.h"
#include "PlayerPawn.h"

void AMainGamePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	check(InputComponent);

	GetMutableDefault<UInputSettings>()->AddAxisMapping(FInputAxisKeyMapping("Player_MovePitch", EKeys::MouseY, 1.f));
	InputComponent->BindAxis("Player_MovePitch", this, &AMainGamePlayerController::AddPitchInput);
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


