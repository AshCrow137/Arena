// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayableZone.h"

#include "Weapons/ArenaProjectile.h"

// Sets default values
APlayableZone::APlayableZone()
{
 
	PrimaryActorTick.bCanEverTick = false;
	
	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	SetRootComponent(BoxComponent);
	BoxComponent->SetGenerateOverlapEvents(true);
	BoxComponent->OnComponentEndOverlap.AddDynamic(this,&APlayableZone::LeavePlayableZone);
	
}

// Called when the game starts or when spawned
void APlayableZone::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayableZone::LeavePlayableZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

	AArenaProjectile* Projectile = Cast<AArenaProjectile>(OtherActor);
	if (Projectile)
	{
		Projectile->Destroy();
		
	}
}

// Called every frame
void APlayableZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

