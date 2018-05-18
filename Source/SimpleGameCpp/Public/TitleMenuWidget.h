// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TitleMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API UTitleMenuWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
		class UButton* SelectEasyButton;
	UPROPERTY()
		class UButton* SelectHardButton;
	
	virtual bool Initialize() override;

};
