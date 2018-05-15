// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MainGameProjectile.generated.h"

UCLASS()
class SIMPLEGAMECPP_API AMainGameProjectile : public AActor
{
	GENERATED_BODY()

public:	
	UPROPERTY()
		class UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION()
		void MoveProjectile(const FVector& Direction, float DeltaTime);

	// Sets default values for this actor's properties
	AMainGameProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
