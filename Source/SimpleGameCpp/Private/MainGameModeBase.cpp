// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameModeBase.h"
#include "UObject/ConstructorHelpers.h"

AMainGameModeBase::AMainGameModeBase(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<APawn> PawnClass(TEXT("/Game/BP_PlayerPawn"));
	if (PawnClass.Succeeded())
	{
		DefaultPawnClass = PawnClass.Class;
	}
}



