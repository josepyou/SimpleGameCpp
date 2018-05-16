// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerPawn.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "GameFramework/PlayerInput.h"
#include "Public/PlayerProjectile.h"
#include "Engine/World.h"

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

	static ConstructorHelpers::FClassFinder<APlayerProjectile> PlayerProjectileClass(TEXT("/Game/BP_PlayerProjectile"));
	if (PlayerProjectileClass.Succeeded())
	{
		ProjectileClass = PlayerProjectileClass.Class;
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

FVector APlayerPawn::GetPlayerMoveDirection(float Direction) const
{
	//UE_LOG(LogTemp, Log, TEXT("MyIntValue=%d"), 5656);

	return (FVector(10.0f, 0.0f, 0.0f) * Direction) + GetActorLocation();
}

void APlayerPawn::MouseMovePitchInput(float val)
{
	SetActorLocation(GetPlayerMoveDirection(val));
}

void APlayerPawn::Fire()
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		FRotator SpawnRotator = FRotator::ZeroRotator;
		FVector SpawnLocation = GetActorLocation() + FVector(0.0f, 50.0f, 0.0f);

		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;

		World->SpawnActor<APlayerProjectile>(ProjectileClass, SpawnLocation, SpawnRotator, SpawnParams);
	}
}
