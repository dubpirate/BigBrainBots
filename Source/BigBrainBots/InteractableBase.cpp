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
    State = false;
    Super::BeginPlay();
    
    LinkTriggerables();
    
//    if(Triggered_Object != nullptr){
//        LinkToTriggerable(Triggered_Object);
//    }
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

bool AInteractableBase::GetState() {
    return State;
}

void AInteractableBase::LinkTriggerables() {
    for(int i = 0; i < Triggerables.Num(); i++){
        Triggerables[i]->AddTrigger(this, Inverted.Contains(Triggerables[i]) ? !State : State);
    }
}

void AInteractableBase::ToggleState() {
    State = !State;
    for(int i = 0; i < Triggerables.Num(); i++){
        Triggerables[i]->UpdateTrigger(this, Inverted.Contains(Triggerables[i]) ? !State : State);
    }
    
//    if(Triggered_Object != nullptr){
//        Triggered_Object->UpdateTrigger(this, State);
//    }
}

void AInteractableBase::SetState(bool newState) {
    State = newState;
    for(int i = 0; i < Triggerables.Num(); i++){
        Triggerables[i]->UpdateTrigger(this, Inverted.Contains(Triggerables[i]) ? !State : State);
    }
}

