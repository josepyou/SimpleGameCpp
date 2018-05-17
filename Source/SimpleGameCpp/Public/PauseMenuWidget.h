// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PauseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API UPauseMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
		class UButton* GoToTitleButton;

	UPROPERTY(meta = (BindWidget))
		class UButton* CloseMenuButton;
	
	UFUNCTION()
		void CloseMenu();
};
