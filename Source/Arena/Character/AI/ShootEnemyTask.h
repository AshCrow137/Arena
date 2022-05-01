// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShootEnemyTask.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UShootEnemyTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UShootEnemyTask();
	
	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	FBlackboardKeySelector AimTargetKey;
	
};