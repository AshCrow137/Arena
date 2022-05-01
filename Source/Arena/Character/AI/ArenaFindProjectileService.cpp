// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ArenaFindProjectileService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ArenaAIPerceptionComponent.h"

UArenaFindProjectileService::UArenaFindProjectileService()
{
	NodeName = "Find projectile";
}

void UArenaFindProjectileService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const UArenaAIPerceptionComponent* PerceptionComponent = Cast<UArenaAIPerceptionComponent>(Controller->GetComponentByClass(UArenaAIPerceptionComponent::StaticClass()));
		if (PerceptionComponent)
		{
			AArenaProjectile* Projectile = PerceptionComponent->GetClosestProjectile();
			if (Projectile)
			{
				Blackboard->SetValueAsObject(ProjectileActorKey.SelectedKeyName,Projectile);
				UE_LOG(LogTemp,Display,TEXT("Projectile in sight"));
			}
			else
			{
			return;
			}
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("Perception component not founded!"));
			
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
