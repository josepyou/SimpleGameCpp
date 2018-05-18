// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainGameProjectile.h"
#include "EnemyProjectile.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API AEnemyProjectile : public AMainGameProjectile
{
	GENERATED_BODY()
	
public:
	AEnemyProjectile();

	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
