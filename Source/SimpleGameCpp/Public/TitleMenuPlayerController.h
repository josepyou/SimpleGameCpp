// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TitleMenuPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API ATitleMenuPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ATitleMenuPlayerController();

	virtual void BeginPlay() override;

	UFUNCTION()
		void OnPushedEasyButton();
	UFUNCTION()
		void OnPushedHardButton();

private:
	TSubclassOf<class UUserWidget> TitleMenuWidgetClass;

	UPROPERTY()
		class UTitleMenuWidget* TitleMenuWidget;
	
	
};
