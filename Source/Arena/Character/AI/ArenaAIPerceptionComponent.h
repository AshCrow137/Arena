// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Arena/Weapons/ArenaProjectile.h"
#include "Perception/AIPerceptionComponent.h"
#include "ArenaAIPerceptionComponent.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UArenaAIPerceptionComponent : public UAIPerceptionComponent
{
	GENERATED_BODY()
public:
	AActor* GetClosestEnemy() const;
	AArenaProjectile* GetClosestProjectile() const;

};
