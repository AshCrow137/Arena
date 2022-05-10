// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ArenaDodgeTask.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "BehaviorTree/BlackboardComponent.h"

UArenaDodgeTask::UArenaDodgeTask()
{
	NodeName = "Dodge";
}

EBTNodeResult::Type UArenaDodgeTask::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	const auto Controller  = OwnerComp.GetAIOwner();
	const auto Blackboard = OwnerComp.GetBlackboardComponent();
	
	if (!Controller || !Blackboard)
	{
		return EBTNodeResult::Failed;
	}
	const auto Pawn = Controller->GetPawn();
	if (!Pawn)
	{
		return EBTNodeResult::Failed;
	}
	const auto NavSys = UNavigationSystemV1::GetCurrent(Pawn);
	if (!NavSys)
	{
		return EBTNodeResult::Failed;
	}
	int32 Direction;
	int32 Randomizer = FMath::RandRange(0,1);
	if (Randomizer==0)
	{
		Direction= 1;
	}
	else
	{
		Direction =-1;
	}

	FNavLocation NavLocation;
	NavLocation.Location = Pawn->GetActorLocation() + Pawn->GetActorRightVector()*DodgeDistance*Direction;
	
	
	Blackboard->SetValueAsVector(DodgeTargetLocation.SelectedKeyName,NavLocation.Location);

	return EBTNodeResult::Succeeded;
}
