// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ArenaProjectile.generated.h"
class USphereComponent;
class ATP_ThirdPersonCharacter;

UCLASS()
class ARENA_API AArenaProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AArenaProjectile();
	
	void SetShotDirection(const FVector& Direction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly,Category="Weapon")
	USphereComponent* SphereComponent;
	UPROPERTY(VisibleDefaultsOnly,Category="Weapon")
	UProjectileMovementComponent* MovementComponent;
	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite,Category="Weapon")
	UStaticMeshComponent* MeshComponent;
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category="Weapon")
	float ProjectileLifeTime = 5.0f;
	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
private:
	
	FVector ShotDirection;

};
