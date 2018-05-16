// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainGameProjectile.h"
#include "PlayerProjectile.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLEGAMECPP_API APlayerProjectile : public AMainGameProjectile
{
	GENERATED_BODY()
	
public:
	APlayerProjectile();

	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	
};
