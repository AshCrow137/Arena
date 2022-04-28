// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Weapons/ArenaProjectile.h"

#include "Arena/ArenaGameInstance.h"
#include "Arena/Character/TP_ThirdPersonCharacter.h"
#include "Components/SphereComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogProjectile, All, All);
// Sets default values
AArenaProjectile::AArenaProjectile()
{
	PrimaryActorTick.bCanEverTick = false;
	
	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->InitSphereRadius(5.0f);
	SetRootComponent(SphereComponent);
	
	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("MeshComponent");
	MeshComponent->SetupAttachment(RootComponent);


	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("ProjectileMovementComponent");
	MovementComponent->bShouldBounce = true;
	MovementComponent->Bounciness = 0.8f;
	MovementComponent->InitialSpeed = 2000.0f;
	MovementComponent->MaxSpeed = 2000.0f;
	MovementComponent->ProjectileGravityScale = 0.0f;
	
}

void AArenaProjectile::SetShotDirection(const FVector& Direction)
{
	ShotDirection = Direction;
}

// Called when the game starts or when spawned
void AArenaProjectile::BeginPlay()
{
	Super::BeginPlay();
	check(SphereComponent);
	check(MovementComponent);
	MovementComponent->Velocity = ShotDirection * MovementComponent->InitialSpeed;
	//SphereComponent->IgnoreActorWhenMoving(GetOwner(),true);
	SphereComponent->OnComponentHit.AddDynamic(this,&AArenaProjectile::OnProjectileHit);

	//MeshComponent->IgnoreActorWhenMoving(GetOwner(),true);

	SetLifeSpan(10.0f);
	
}

// Called every frame
void AArenaProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AArenaProjectile::OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	
	if (!GetWorld())return;
	ATP_ThirdPersonCharacter* HittedCharacter = Cast<ATP_ThirdPersonCharacter>(OtherActor);
	if (HittedCharacter&&HittedCharacter!=GetOwner())
	{
		UE_LOG(LogProjectile,Display,TEXT("Hitted %s"),*HittedCharacter->GetName())
		
		if (HittedCharacter->bIsAIControlled)
		{
			UArenaGameInstance* GameInstance = Cast<UArenaGameInstance>(GetGameInstance());
			if (GameInstance)
			{
				GameInstance->UpPlayerScore();
			}
		}
		else if (!HittedCharacter->bIsAIControlled)
		{
			UArenaGameInstance* GameInstance = Cast<UArenaGameInstance>(GetGameInstance());
			if (GameInstance)
			{
				GameInstance->UpAIScore();
			}
			
		}
		MovementComponent->StopMovementImmediately();
		Destroy();
	
	}

	
	
}


