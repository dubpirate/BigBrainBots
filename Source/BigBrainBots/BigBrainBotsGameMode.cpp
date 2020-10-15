// Copyright Epic Games, Inc. All Rights Reserved.
#include "BigBrainBotsGameMode.h"
#include "BigBrainBotsPlayerController.h"
#include "BigBrainBotsCharacter.h"
#include "UObject/ConstructorHelpers.h"

ABigBrainBotsGameMode::ABigBrainBotsGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ABigBrainBotsPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/StandardBot_BP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
