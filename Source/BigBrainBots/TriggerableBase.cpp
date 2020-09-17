// Fill out your copyright notice in the Description page of Project Settings.

#include <cstdlib>
#include "TriggerableBase.h"

// Sets default values
ATriggerableBase::ATriggerableBase()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ATriggerableBase::BeginPlay()
{
    Super::BeginPlay();

}

// Called every frame
void ATriggerableBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

//Adds a new trigger to the trigger map
void ATriggerableBase::AddTrigger(AInteractableBase* trigger, bool state) {
    triggerMap[trigger] = state;
    BlueprintStuff();
}

//Looks up a trigger in the trigger map, and updates its stored boolean value.
void ATriggerableBase::UpdateTrigger(AInteractableBase* trigger, bool newState) {
    if (triggerMap.count(trigger) > 0) {
        triggerMap[trigger] = newState;
    }
    BlueprintStuff();
}

//returns the current state of the object (if all triggers are true). Calls "blueprintStuff" at the end
bool ATriggerableBase::EvaulateTriggers() {
    
    for (auto i = triggerMap.begin(); i != triggerMap.cend(); i++) {
        if (i->second == false) {
            return false;
        }
    }
    return true;
}

//Called to pass actions up to blueprint level. Has no code by default.
void ATriggerableBase::BlueprintStuff_Implementation() {
    
}
