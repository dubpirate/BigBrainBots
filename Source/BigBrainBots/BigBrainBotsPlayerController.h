// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BotParent.h"
#include "BigBrainBotsPlayerController.generated.h"

UCLASS()
class ABigBrainBotsPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	ABigBrainBotsPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Movement methods */
	void MoveForward(float Value);
	void MoveRight(float Value);

	/** Switch to the next bot */
	//void switchBot();

	void NextBot();

	void PrevBot();

	void PickBot(int i);

	DECLARE_DELEGATE_OneParam(FPickBotDelegate, int);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

private:
	TArray<ABotParent*> BotArray;
};


