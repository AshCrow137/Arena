// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ArenaAIPerceptionComponent.h"
#include "AIController.h"
#include "Perception/AISense_Sight.h"

DECLARE_LOG_CATEGORY_CLASS(LogAIPerceptionComponent,All,All);

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
		UE_LOG(LogAIPerceptionComponent,Warning,TEXT("No controller!"))
		return nullptr;
	}
	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		UE_LOG(LogAIPerceptionComponent,Warning,TEXT("No Pawn!"))
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

AActor* UArenaAIPerceptionComponent::GetClosestProjectile() const
{
	TArray<AActor*> PerceiveActors;
	GetCurrentlyPerceivedActors(UAISense_Sight::StaticClass(),PerceiveActors);
	if (PerceiveActors.Num() == 0 )
	{
		UE_LOG(LogAIPerceptionComponent,Warning,TEXT("No actors in sight!"))
		return nullptr;
	}
	const auto Controller = Cast<AAIController>(GetOwner());
	if (!Controller)
	{
		UE_LOG(LogAIPerceptionComponent,Warning,TEXT("No controller!"))
		return nullptr;
	}
	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		UE_LOG(LogAIPerceptionComponent,Warning,TEXT("No Pawn!"))
		return nullptr;
	}
	float BestDistance = MAX_FLT;
	AActor* Projectile= nullptr;
	for (const auto PerciveActor: PerceiveActors)
	{
	
		const auto CurrentDistance = (PerciveActor->GetActorLocation() - Pawn->GetActorLocation()).Size();
		if (CurrentDistance<BestDistance)
		{
			UE_LOG(LogAIPerceptionComponent,Display,TEXT("Actor in sight: %s"),*PerciveActor->GetName());
			BestDistance = CurrentDistance;
			Projectile =PerciveActor ;
			
		}
	}
	if (!Projectile)
	{
		UE_LOG(LogAIPerceptionComponent,Warning,TEXT("No Projectile!"))
		return nullptr;
	}
	return Projectile;
	
}
