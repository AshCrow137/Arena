// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ArenaFindProjectileService.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UArenaFindProjectileService : public UBTService
{
	GENERATED_BODY()
public:
	UArenaFindProjectileService();
protected:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	FBlackboardKeySelector ProjectileActorKey;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};

