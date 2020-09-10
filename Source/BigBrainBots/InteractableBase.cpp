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
}

// Called every frame
void AInteractableBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractableBase::ToggleState(){
    State = !State;
}

void AInteractableBase::SetState(bool newState){
    State = newState;
}

bool AInteractableBase::GetState(){
    return State;
}

