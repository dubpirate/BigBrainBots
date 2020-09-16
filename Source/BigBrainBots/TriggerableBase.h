// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <map>
#include <iterator>

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerableBase.generated.h"

class AInteractableBase; //forward declaration for compiler health

UCLASS()
class BIGBRAINBOTS_API ATriggerableBase : public AActor
{
    GENERATED_BODY()

private:
    std::map<AInteractableBase*, bool> triggerMap;

public:
    // Sets default values for this actor's properties
    ATriggerableBase();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    //Adds a new trigger to the trigger map
    UFUNCTION(BlueprintCallable)
    void AddTrigger(AInteractableBase* trigger);

    //Looks up a trigger in the trigger map, and updates its stored boolean value.
    UFUNCTION(BlueprintCallable)
    void UpdateTrigger(AInteractableBase* trigger, bool newState);

    //returns the current state of the object (if all triggers are true). Calls "blueprintStuff" at the end
    UFUNCTION(BlueprintCallable)
    bool EvaulateTriggers();

    //Called to pass actions up to blueprint level
    UFUNCTION(BlueprintNativeEvent)
        void BlueprintStuff();

};