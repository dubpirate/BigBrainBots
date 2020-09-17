// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractableBase.h"


// Sets default values
AInteractableBase::AInteractableBase()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    State = false;

}

// Called when the game starts or when spawned
void AInteractableBase::BeginPlay()
{
    Super::BeginPlay();
    if(Triggered_Object != nullptr){
        LinkToTriggerable(Triggered_Object);
    }
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

bool AInteractableBase::GetState() {
    return State;
}

void AInteractableBase::LinkToTriggerable(ATriggerableBase* triggerable) {
    if(triggerable != nullptr){
        Triggered_Object = triggerable;
        Triggered_Object->ATriggerableBase::AddTrigger(this, State);
    }
}

void AInteractableBase::ToggleState() {
    State = !State;
    if(Triggered_Object != nullptr){
        Triggered_Object->UpdateTrigger(this, State);
    }
}

void AInteractableBase::SetState(bool newState) {
    State = newState;
    if(Triggered_Object != nullptr){
        Triggered_Object->UpdateTrigger(this, State);
    }
}

