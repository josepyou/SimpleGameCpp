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
	AMainGamePlayerController();

private:
	UPROPERTY()
		TArray<class AGameCameraActor*> GameCameras;

	UFUNCTION(BlueprintCallable)
		class AGameCameraActor* ChangeGameCamera(const FName& Tag);

public:
	virtual void SetupInputComponent() override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable, Category = "Game|Player", meta = (Keywords = "up down"))
		virtual void AddPitchInput(float val) override;
	void Fire();

	UFUNCTION()
		void OnPauseMenu();
	
	UPROPERTY()
		TSubclassOf<class UPauseMenuWidget> PauseMenuWidgetClass;

	UPROPERTY()
		class UPauseMenuWidget* PauseMenuWidget;

	UFUNCTION()
		void OnPauseMenuGotoTitleButton();

	UFUNCTION()
		void OnPauseMenuCloseButton();
};
