// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/PlayerInput.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

APlayerPawn::APlayerPawn(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	USceneComponent* NewRootSceneComponent = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("NewRootComponent"));
	if (NewRootSceneComponent != nullptr)
	{
		RootComponent = NewRootSceneComponent;
	}

	StaticMeshComponent = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("StaticMesh"));
	if (StaticMeshComponent != nullptr)
	{
		StaticMeshComponent->SetupAttachment(RootComponent);
	}

	static ConstructorHelpers::FObjectFinder<UStaticMesh>PlayerMeshObj(TEXT("/Game/SM_Player.SM_Player"));
	if (PlayerMeshObj.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(PlayerMeshObj.Object);
	}

	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bAddDefaultMovementBindings = true;

}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (bAddDefaultMovementBindings)
	{
		InitializeDefaultPawnInputBindings();
		PlayerInputComponent->BindAxis("DefaultPawn_Turn", this, &APlayerPawn::AddControllerYawInput);
	}

}

FVector APlayerPawn::GetPlayerMoveDirection(float Direction) const
{
	//UE_LOG(LogTemp, Log, TEXT("MyIntValue=%d"), 5656);

	return (FVector(10.0f, 0.0f, 0.0f) * Direction) + GetActorLocation();
}

void APlayerPawn::AddControllerYawInput(float Val)
{
	Super::AddControllerYawInput(Val);
	SetActorLocation(GetPlayerMoveDirection(Val));
}


void APlayerPawn::MouseMovePitchInput(float val)
{
	SetActorLocation(GetPlayerMoveDirection(val));
}

void APlayerPawn::InitializeDefaultPawnInputBindings()
{
	static bool bBindingsAdded = false;
	if (!bBindingsAdded)
	{
		bBindingsAdded = true;
		UPlayerInput::AddEngineDefinedAxisMapping(FInputAxisKeyMapping("DefaultPawn_Turn", EKeys::MouseX, 1.f));
	}
}
