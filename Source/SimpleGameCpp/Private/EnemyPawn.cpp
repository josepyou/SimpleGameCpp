// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyPawn.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/StaticMesh.h"
#include "Public/EnemyProjectile.h"


// Sets default values
AEnemyPawn::AEnemyPawn()
	: Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> EnemyMeshObj(TEXT("/Game/SM_Enemy.SM_Enemy"));
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	if (StaticMeshComponent != nullptr && EnemyMeshObj.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(EnemyMeshObj.Object);
		RootComponent = StaticMeshComponent;
	}

	static ConstructorHelpers::FClassFinder<AEnemyProjectile> EnemyProjectileClass(TEXT("/Game/BP_EnemyProjectile"));
	if (EnemyProjectileClass.Succeeded())
	{
		ProjectileClass = EnemyProjectileClass.Class;
	}


	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// initialize
	DirectionX = -1.0f;
	RemainingShotTime = 0.0f;
}

// Called when the game starts or when spawned
void AEnemyPawn::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	FVector location = ((FVector(200.0f, 0.f, 0.f) * DeltaTime) * (FVector(1.0f, 0.f, 0.f) * DirectionX)) + GetActorLocation();
	SetActorLocation(location);

	if (location.X > 300.0f)
	{
		DirectionX = -1.0f;
	}
	else if (location.X < -300.0f)
	{
		DirectionX = 1.0f;
	}

	RemainingShotTime -= DeltaTime;
	if (RemainingShotTime <= 0.0f)
	{
		UWorld* World = GetWorld();
		if (World != nullptr)
		{
			FRotator SpawnRotator = FRotator::ZeroRotator;
			FVector SpawnLocation = GetActorLocation() + FVector(0.0f, -50.0f, 0.0f);
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			World->SpawnActor<AEnemyProjectile>(ProjectileClass, SpawnLocation, SpawnRotator, SpawnParams);
		}
		ReloadProjectile();
	}
}

void AEnemyPawn::ReloadProjectile()
{
	RemainingShotTime = FMath::RandRange(1.0f, 2.0f);
}

// Called to bind functionality to input
void AEnemyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

