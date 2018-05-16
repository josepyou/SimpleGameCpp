// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/DefaultPawn.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SIMPLEGAMECPP_API APlayerPawn : public ADefaultPawn
{
	GENERATED_BODY()

private:
	UPROPERTY(BlueprintReadonly, VisibleAnywhere, Category = "PlayerMesh", meta = (AllowPrivateAccess = true))
		class UStaticMeshComponent* StaticMeshComponent;

	UFUNCTION(BlueprintPure)
		FVector GetPlayerMoveDirection(float Direction) const;

	UPROPERTY()
		TSubclassOf<class APlayerProjectile> ProjectileClass;

	UPROPERTY()
		TSubclassOf<AActor> ExplosionClass;

public:
	// Sets default values for this pawn's properties
	APlayerPawn();
	APlayerPawn(const FObjectInitializer& ObjectInitializer);

	UFUNCTION()
		void MouseMovePitchInput(float val);

	UFUNCTION()
		void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	uint32 bAddDefaultMovementBindings = 1;

	void Fire();
};
