// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerProjectile.h"
#include "UObject/ConstructorHelpers.h"

APlayerProjectile::APlayerProjectile()
	: Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_PlayerProjectile.SM_PlayerProjectile"));
	if (StaticMeshComponent != nullptr && ProjectileMesh.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
	}
}

void APlayerProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MoveProjectile(FVector(0.0f, 400.0f, 0.0f), DeltaTime);
}

