// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"

APlayerProjectile::APlayerProjectile()
	: Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_PlayerProjectile.SM_PlayerProjectile"));
	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}

	OnActorBeginOverlap.AddDynamic(this, &APlayerProjectile::OnBeginOverlap);
}

void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}

void APlayerProjectile::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		World->DestroyActor(this);
	}
}
