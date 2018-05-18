// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleMenuGameMode.h"
#include "UObject/ConstructorHelpers.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameInstance.h"

ATitleMenuGameMode::ATitleMenuGameMode()
	: Super()
{
	static ConstructorHelpers::FClassFinder<APlayerController> PCClass(TEXT("/Game/BP_TitleMenuPlayerController"));
	if (PCClass.Succeeded())
	{
		PlayerControllerClass = PCClass.Class;
	}
}

void ATitleMenuGameMode::StartGame(EMyGameDifficultType Type)
{
	UMyGameInstance* GameInstance = Cast<UMyGameInstance>(GetGameInstance());
	if (GameInstance != nullptr)
	{
		GameInstance->DifficultType = Type;
		UGameplayStatics::OpenLevel(this, TEXT("/Game/MainGame"));
	}
}