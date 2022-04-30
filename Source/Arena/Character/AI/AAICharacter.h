// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Arena/Character/TP_ThirdPersonCharacter.h"
#include "AAICharacter.generated.h"
class UBehaviorTree;


/**
 * 
 */
UCLASS()
class ARENA_API AAAICharacter : public ATP_ThirdPersonCharacter
{
	GENERATED_BODY()

public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadWrite,Category="AI")
	UBehaviorTree* BechaviorTreeAsset;
	
};
