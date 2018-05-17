// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyProjectile.h"
#include "UObject/ConstructorHelpers.h"

AEnemyProjectile::AEnemyProjectile()
	: Super()
{
	static ConstructorHelpers::FObjectFinder<UStaticMesh> ProjectileMesh(TEXT("/Game/SM_EnemyProjectile.SM_EnemyProjectile"));
	if (StaticMeshComponent != nullptr)
	{
		StaticMeshComponent->SetStaticMesh(ProjectileMesh.Object);
		StaticMeshComponent->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	}

	Tags.AddUnique(TEXT("EnemyType"));

	OnActorBeginOverlap.AddDynamic(this, &AEnemyProjectile::OnBeginOverlap);

}

void AEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MoveProjectile(FVector(0.0f, -200.0f, 0.0f), DeltaTime);
}

void AEnemyProjectile::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UWorld* World = GetWorld();
	if (World != nullptr)
	{
		if (OtherActor != nullptr)
		{
			if (OtherActor->ActorHasTag(TEXT("PlayerType")))
			{
				World->DestroyActor(this);
			}
		}
	}

}
