// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MyGameTypes.h"
#include "MyGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UMyGameInstance();

public:
	UPROPERTY(BlueprintReadWrite, Category = "MainGameConfig")
	EMyGameDifficultType DifficultType;
	
	
};
