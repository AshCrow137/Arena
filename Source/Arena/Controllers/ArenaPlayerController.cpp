// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArenaPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Arena/Character/TP_ThirdPersonCharacter.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"

AArenaPlayerController::AArenaPlayerController()
{
	
	
}



void AArenaPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	
}


