// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ShootEnemyTask.h"

#include "AAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UShootEnemyTask::UShootEnemyTask()
{
	NodeName = "Shoot Enemy";
}

EBTNodeResult::Type UShootEnemyTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller  = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	if (!Controller || !Blackboard)
	{
		return EBTNodeResult::Failed;
	}
	const auto Owner= Cast<AAAICharacter>(Controller->GetPawn()) ;
	if (!Owner)
	{
		return EBTNodeResult::Failed;
	}
	Owner->MakeShot();
	return EBTNodeResult::Succeeded;
	
}
