// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "ArenaDodgeTask.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UArenaDodgeTask : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UArenaDodgeTask();

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	float DodgeDistance = 100.0f;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	FBlackboardKeySelector DodgeTargetLocation;
};
