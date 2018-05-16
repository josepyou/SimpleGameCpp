// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainGamePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API AMainGamePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void SetupInputComponent() override;

	UFUNCTION(BlueprintCallable, Category = "Game|Player", meta = (Keywords = "up down"))
		virtual void AddPitchInput(float val) override;
	void Fire();
};
