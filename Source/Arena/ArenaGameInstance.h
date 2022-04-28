// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ArenaGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARENA_API UArenaGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Player")
	int32 PlayerOneScore = 0;
	UPROPERTY(BlueprintReadWrite,EditAnywhere,Category="Player")
	int32 PlayerTwoScore = 0;

	UFUNCTION(BlueprintNativeEvent)
	void UpPlayerScore();
	UFUNCTION(BlueprintNativeEvent)
	void UpAIScore();
	
};
