// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MyGameTypes.h"
#include "TitleMenuGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API ATitleMenuGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ATitleMenuGameMode();
	
	UFUNCTION()
		void StartGame(EMyGameDifficultType Type);
};
