// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Arena/Weapons/ArenaProjectile.h"
#include "GameFramework/Character.h"
#include "Components/StaticMeshComponent.h"
#include "TP_ThirdPersonCharacter.generated.h"

UCLASS(config=Game)
class ATP_ThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

	virtual void Tick(float DeltaSeconds) override;

	
public:
	ATP_ThirdPersonCharacter();
	//Use to Aim with mouse
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Weapon")
	bool bUseMouseToAim = true;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon")
	bool bUseFireRate = false;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon")
	float FireRate = 2.0f;
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category="Character")
	float TurnSpeed = 5.0f;

	//Used to change player/enemy score
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category="Character")
	bool bIsAIControlled = false;

	void MakeShot();
	

protected:

	void MoveForward(float Value);

	void MoveRight(float Value);
	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY( EditDefaultsOnly, BlueprintReadWrite,Category="Character")
	UStaticMeshComponent* WeaponMesh;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon")
	TSubclassOf<AArenaProjectile> ProjectileClass;
	


private:

	bool bIsAiming = false;
	void TurnAround(float Value);

	

	
	//Used to aim with mouse, boolean can be enabled in BP
	void StartAim();
	void StopAim();
	void RotateToCoursor();

	void StartShooting();
	void StopShooting();

	
	FTimerHandle ShootTimerHandle;


};

