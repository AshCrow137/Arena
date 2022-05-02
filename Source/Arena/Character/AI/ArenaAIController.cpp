// Fill out your copyright notice in the Description page of Project Settings.


#include "Arena/Character/AI/ArenaAIController.h"
#include "Arena/Character/AI/AAICharacter.h"
#include "Arena/Character/AI/ArenaAIPerceptionComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BlackboardComponent.h"

AArenaAIController::AArenaAIController()
{
	ArenaPerceptionComponent = CreateDefaultSubobject<UArenaAIPerceptionComponent>("PerceptionComponent");
	SetPerceptionComponent(*ArenaPerceptionComponent);
		 
}

void AArenaAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	
	const auto AimActor = GetFocusOnActor();
	SetFocus(AimActor);
	
}

void AArenaAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	const auto AiCharacter = Cast<AAAICharacter>(InPawn);
	if (AiCharacter)
	{
		RunBehaviorTree(AiCharacter->BechaviorTreeAsset);  
	}
}

AActor* AArenaAIController::GetFocusOnActor() const
{
	if (!GetBlackboardComponent())
	{
		return nullptr;
	}
	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));
}
