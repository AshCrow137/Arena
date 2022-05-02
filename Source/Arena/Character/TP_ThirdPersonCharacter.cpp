// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_ThirdPersonCharacter.h"
#include "Arena/Controllers/ArenaPlayerController.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"


DEFINE_LOG_CATEGORY_STATIC(LogBaseCharacter, All, All);



ATP_ThirdPersonCharacter::ATP_ThirdPersonCharacter()
{
	
	SetActorTickEnabled(true);
	WeaponMesh=CreateDefaultSubobject<UStaticMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(RootComponent);
	
}


void ATP_ThirdPersonCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	if (bUseMouseToAim)
	{
		RotateToCoursor();
	}
	
}



void ATP_ThirdPersonCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ATP_ThirdPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ATP_ThirdPersonCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &ATP_ThirdPersonCharacter::TurnAround);
	
//  Can be enabled to aim with pressed RMB if needs to 
//	PlayerInputComponent->BindAction("Aim",IE_Pressed,this,&ATP_ThirdPersonCharacter::StartAim);
//	PlayerInputComponent->BindAction("Aim",IE_Released,this,&ATP_ThirdPersonCharacter::StopAim);

	PlayerInputComponent->BindAction("Shoot",IE_Pressed,this,&ATP_ThirdPersonCharacter::StartShooting);
	PlayerInputComponent->BindAction("Shoot",IE_Released,this,&ATP_ThirdPersonCharacter::StopShooting);

	
}


void ATP_ThirdPersonCharacter::TurnAround(float Value)
{
	if(Value==0)return;
	
	FRotator NewRotation = FRotator(0,this->GetActorRotation().Yaw +(TurnSpeed*Value),0);
	this->SetActorRotation(NewRotation);
}

void ATP_ThirdPersonCharacter::StartAim()
{
	bIsAiming = true;
}

void ATP_ThirdPersonCharacter::StopAim()
{
	bIsAiming = false;
	
}

void ATP_ThirdPersonCharacter::RotateToCoursor()
{
	if (Controller)
	{
		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
		if (PlayerController)
		{
			
			FHitResult HitResult;
			PlayerController->GetHitResultUnderCursorByChannel(ETraceTypeQuery::TraceTypeQuery_MAX,true,HitResult);
			const FVector StartLocation = GetActorLocation();
			const FVector NewRotationLocation = HitResult.Location;
			const FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(StartLocation,NewRotationLocation);
			const FRotator NewRotation = FRotator(0,TargetRotation.Yaw,0);
			
		
			this->SetActorRotation(NewRotation);
			
		}
		
	}
}

void ATP_ThirdPersonCharacter::StartShooting()
{
	if (bUseFireRate)
	{
		GetWorldTimerManager().SetTimer(ShootTimerHandle,this,&ATP_ThirdPersonCharacter::MakeShot,FireRate,true);
	}
	MakeShot();
}

void ATP_ThirdPersonCharacter::StopShooting()
{
	if (bUseFireRate)
	{
		GetWorldTimerManager().ClearTimer(ShootTimerHandle);
	}

	
}

void ATP_ThirdPersonCharacter::MakeShot()
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(),0);
	if (PlayerController)
	{
		
		FHitResult HitResult;
		PlayerController->GetHitResultUnderCursorByChannel(ETraceTypeQuery::TraceTypeQuery_MAX,true,HitResult);
		const FVector TraceStart = WeaponMesh->GetComponentLocation();
		const FVector Direction = WeaponMesh->GetForwardVector();
		
		const FTransform SpawnTransform(FRotator::ZeroRotator,TraceStart);
		AArenaProjectile* Projectile = GetWorld()->SpawnActorDeferred<AArenaProjectile>(ProjectileClass,SpawnTransform);
		if (Projectile)
		{
			Projectile->SetOwner(this);
			Projectile->SetShotDirection(Direction);
			Projectile->FinishSpawning(SpawnTransform);
		}
	}
}


void ATP_ThirdPersonCharacter::MoveForward(float Value)
{
	if (Value ==0)return;
	AddMovementInput(GetActorForwardVector(), Value,true);
}

void ATP_ThirdPersonCharacter::MoveRight(float Value)
{
	if ( Value ==0 )return;
	AddMovementInput(GetActorRightVector(), Value);
}
