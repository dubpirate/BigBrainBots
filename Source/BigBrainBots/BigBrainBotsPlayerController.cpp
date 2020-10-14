// Copyright Epic Games, Inc. All Rights Reserved.

#include "BigBrainBotsPlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "BigBrainBotsCharacter.h"
#include "BotParent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"

ABigBrainBotsPlayerController::ABigBrainBotsPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABotParent::StaticClass(), FoundActors);

	BotArray.Init(nullptr, 4);

	for (int i = 0; i < FoundActors.Num(); i++) {
		FString botClass = FoundActors[i]->GetClass()->GetName();

		if (botClass == FString("StandardBot_BP_C")) { BotArray[0] = (ABotParent*)FoundActors[i]; }
		if (botClass == FString("HeavyBot_BP_C")) { BotArray[1] = (ABotParent*)FoundActors[i]; }
		if (botClass == FString("FlyBot_BP_C")) { BotArray[2] = (ABotParent*)FoundActors[i]; }
		if (botClass == FString("GasBot_BP_C")) { BotArray[3] = (ABotParent*)FoundActors[i]; }
	}

}

void ABigBrainBotsPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void ABigBrainBotsPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	//Movement (mouse)
	InputComponent->BindAction("SetDestination", IE_Pressed, this, &ABigBrainBotsPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &ABigBrainBotsPlayerController::OnSetDestinationReleased);

	//Movement (WASD/Controller)
	InputComponent->BindAxis("MoveForward", this, &ABigBrainBotsPlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ABigBrainBotsPlayerController::MoveRight);

	//Switching Bot
	InputComponent->BindAction("NextBot", IE_Pressed, this, &ABigBrainBotsPlayerController::NextBot);
	InputComponent->BindAction("PrevBot", IE_Pressed, this, &ABigBrainBotsPlayerController::PrevBot);

	InputComponent->BindAction<FPickBotDelegate>("SBotSwitch", IE_Pressed, this, &ABigBrainBotsPlayerController::PickBot, 0);
	InputComponent->BindAction<FPickBotDelegate>("HBotSwitch", IE_Pressed, this, &ABigBrainBotsPlayerController::PickBot, 1);
	InputComponent->BindAction<FPickBotDelegate>("FBotSwitch", IE_Pressed, this, &ABigBrainBotsPlayerController::PickBot, 2);
	InputComponent->BindAction<FPickBotDelegate>("GBotSwitch", IE_Pressed, this, &ABigBrainBotsPlayerController::PickBot, 3);

	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &ABigBrainBotsPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &ABigBrainBotsPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &ABigBrainBotsPlayerController::OnResetVR);
}

void ABigBrainBotsPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void ABigBrainBotsPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (ABigBrainBotsCharacter* MyPawn = Cast<ABigBrainBotsCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void ABigBrainBotsPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void ABigBrainBotsPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void ABigBrainBotsPlayerController::MoveForward(float Value) {
	APawn* const MyPawn = GetPawn();
	if (MyPawn) {
		/* find out which way is forward **RELATIVE TO THE PLAYERS CURRENT DIRECTION**
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		*/

		// Go forward, where forward = +x direction.
		const FVector Direction = *(new FVector(1, 0, 0));
		MyPawn->AddMovementInput(Direction, Value);
	}
}

void ABigBrainBotsPlayerController::MoveRight(float Value) {
	APawn* const MyPawn = GetPawn();
	if (MyPawn) {

		/* find out which way is right, RELATIVE TO THE PLAYER'S CURRENT DIRECTION.
		const FRotator Rotation = GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		*/

		// Go right, where right = +y direction.
		const FVector Direction = *(new FVector(0, 1, 0));
		// add movement in that direction
		MyPawn->AddMovementInput(Direction, Value);
	}
}

void ABigBrainBotsPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void ABigBrainBotsPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void ABigBrainBotsPlayerController::NextBot() {

	ABotParent* currentBot = dynamic_cast<ABotParent*>(GetPawn());
	if (currentBot == nullptr) { return; }

	int32 index = BotArray.Find(currentBot);
	for (int i = 1; i < BotArray.Num(); i++) {
		ABotParent* newBot = BotArray[(i + index) % BotArray.Num()];

		if (newBot->Is_Active) {
			UnPossess();
			Possess(newBot);
			return;
		}
	}
}

void ABigBrainBotsPlayerController::PrevBot()
{
	ABotParent* currentBot = dynamic_cast<ABotParent*>(GetPawn());
	if (currentBot == nullptr) { return; }

	int32 index = BotArray.Find(currentBot);
	UE_LOG(LogTemp, Warning, TEXT("index: %d"), index);
	for (int i = BotArray.Num() - 1; i >= 1; i++) {	
		ABotParent* newBot = BotArray[(i + index) % BotArray.Num()];

		if (newBot->Is_Active) {
			UnPossess();
			Possess(newBot);
			return;
		}
	}
}

void ABigBrainBotsPlayerController::PickBot(int i)
{
	if (i < 0 || i >= BotArray.Num()) { return; }
	ABotParent* newBot = BotArray[i];

	if (newBot->Is_Active) {
		UnPossess();
		Possess(newBot);
		return;
	}
}

