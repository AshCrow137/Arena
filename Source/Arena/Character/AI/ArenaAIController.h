// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ArenaAIController.generated.h"
class UArenaAIPerceptionComponent;

/**
 * 
 */
UCLASS()
class ARENA_API AArenaAIController : public AAIController
{
	GENERATED_BODY()
public:
	AArenaAIController();

	virtual void Tick(float DeltaSeconds) override;
	
protected:
	virtual void OnPossess(APawn* InPawn) override;;
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite,Category="AI")
	UArenaAIPerceptionComponent* ArenaPerceptionComponent;
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="AI")
	FName FocusOnKeyName = "EnemyActor";

private:
	AActor* GetFocusOnActor() const;
	
};
