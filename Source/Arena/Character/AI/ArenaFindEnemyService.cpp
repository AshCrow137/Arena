// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ArenaFindEnemyService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "ArenaAIPerceptionComponent.h"
#include "Arena/Character/TP_ThirdPersonCharacter.h"

UArenaFindEnemyService::UArenaFindEnemyService()
{
	NodeName = "Find Enemy";
}

void UArenaFindEnemyService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (Blackboard)
	{
		const auto Controller = OwnerComp.GetAIOwner();
		const UArenaAIPerceptionComponent* PerceptionComponent = Cast<UArenaAIPerceptionComponent>(Controller->GetComponentByClass(UArenaAIPerceptionComponent::StaticClass()));
		if (PerceptionComponent)
		{
			ATP_ThirdPersonCharacter* Character = Cast<ATP_ThirdPersonCharacter>(PerceptionComponent->GetClosestEnemy());
			if (Character)
			{
				Blackboard->SetValueAsObject(EnemyActorKey.SelectedKeyName,Character);

			}
		}
		else
		{
			UE_LOG(LogTemp,Warning,TEXT("Perception component not founded!"));
			
		}
	}
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);
}
