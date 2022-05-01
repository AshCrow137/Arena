// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ArenaAIPerceptionComponent.h"
#include "AIController.h"
#include "Perception/AISense_Sight.h"

AActor* UArenaAIPerceptionComponent::GetClosestEnemy() const
{
	TArray<AActor*> PerceiveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(),PerceiveActors);
	if (PerceiveActors.Num() == 0 )
	{
		return nullptr;
	}
	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller)
	{
		return nullptr;
	}
	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		return nullptr;
	}
	float BestDistance = MAX_FLT;
	AActor* BestPawn = nullptr;
	for (const auto PerciveActor: PerceiveActors)
	{
		const auto CurrentDistance = (PerciveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
		if (CurrentDistance<BestDistance)
		{
			BestDistance = CurrentDistance;
			BestPawn = PerciveActor;
			
		}
	}
	return BestPawn;
	
}

AArenaProjectile* UArenaAIPerceptionComponent::GetClosestProjectile() const
{
	TArray<AActor*> PerceiveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(),PerceiveActors);
	if (PerceiveActors.Num() == 0 )
	{
		return nullptr;
	}
	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller)
	{
		return nullptr;
	}
	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		return nullptr;
	}
	float BestDistance = MAX_FLT;
	AArenaProjectile* Projectile= nullptr;
	for (const auto PerciveActor: PerceiveActors)
	{
		
		const auto CurrentDistance = (PerciveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
		if (CurrentDistance<BestDistance)
		{
			BestDistance = CurrentDistance;
			Projectile =Cast<AArenaProjectile>(PerciveActor) ;
			
		}
	}
	return Projectile;
	
}
