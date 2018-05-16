// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameProjectile.h"


// Sets default values
AMainGameProjectile::AMainGameProjectile()
	: Super()
{
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = StaticMeshComponent;


	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainGameProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainGameProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMainGameProjectile::MoveProjectile(const FVector& Direction, float DeltaTime)
{
	SetActorLocation((Direction * DeltaTime) + GetActorLocation());
}

