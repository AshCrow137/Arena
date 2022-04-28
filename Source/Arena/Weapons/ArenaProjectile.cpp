// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Weapons/ArenaProjectile.h"

#include "Arena/Character/TP_ThirdPersonCharacter.h"
#include "Components/SphereComponent.h"

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
	SphereComponent->IgnoreActorWhenMoving(GetOwner(),true);

	
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
	
		MovementComponent->StopMovementImmediately();
	
		Destroy();
	
	
	
}


