// Fill out your copyright notice in the Description page of Project Settings.

#include "TitleMenuPlayerController.h"
#include "UObject/ConstructorHelpers.h"
#include "UserWidget.h"
#include "TitleMenuWidget.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "TitleMenuGameMode.h"

ATitleMenuPlayerController::ATitleMenuPlayerController()
	: Super()
{
	static ConstructorHelpers::FClassFinder<UUserWidget> WidgetClass(TEXT("/Game/WBP_TitleMenu"));
	if (WidgetClass.Succeeded())
	{
		TitleMenuWidgetClass = WidgetClass.Class;
	}
}

void ATitleMenuPlayerController::BeginPlay()
{
	if (TitleMenuWidgetClass != nullptr)
	{
		TitleMenuWidget = CreateWidget<UTitleMenuWidget>(this, TitleMenuWidgetClass.Get());

		if (TitleMenuWidget)
		{
			TitleMenuWidget->AddToViewport(0);
			TitleMenuWidget->SelectEasyButton->OnClicked.AddDynamic(this, &ATitleMenuPlayerController::OnPushedEasyButton);
			TitleMenuWidget->SelectHardButton->OnClicked.AddDynamic(this, &ATitleMenuPlayerController::OnPushedHardButton);
		}
	}

	bShowMouseCursor = true;
	Super::BeginPlay();
}

void ATitleMenuPlayerController::OnPushedEasyButton()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		ATitleMenuGameMode* GameMode = World->GetAuthGameMode<ATitleMenuGameMode>();
		if (GameMode != nullptr)
		{
			GameMode->StartGame(EMyGameDifficultType::EASY);
		}
	}
}

void ATitleMenuPlayerController::OnPushedHardButton()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		ATitleMenuGameMode* GameMode = World->GetAuthGameMode<ATitleMenuGameMode>();
		if (GameMode != nullptr)
		{
			GameMode->StartGame(EMyGameDifficultType::HARD);
		}
	}
}
