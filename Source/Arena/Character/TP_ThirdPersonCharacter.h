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
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category= "Weapon")
	bool bUseMouseToAim = true;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon")
	bool bUseFireRate = false;
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon")
	float FireRate = 2.0f;
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category="Character")
	float TurnSpeed = 5.0f;
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category="Character")
	bool bIsAIControlled = false;


	

protected:

	

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);





protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface
	UPROPERTY( EditAnywhere, BlueprintReadWrite,Category="Character")
	UStaticMeshComponent* WeaponMesh;
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="Weapon")
	TSubclassOf<AArenaProjectile> ProjectileClass;

private:

	bool bIsAiming = false;
	void TurnAround(float Value);
	
	void StartAim();
	void StopAim();
	void RotateToCoursor();

	void StartShooting();
	void StopShooting();
	void MakeShot();
	
	FTimerHandle ShootTimerHandle;


};

