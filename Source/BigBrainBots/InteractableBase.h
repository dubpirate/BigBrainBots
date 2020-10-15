// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TriggerableBase.h"
#include "InteractableBase.generated.h"

UCLASS()
class BIGBRAINBOTS_API AInteractableBase : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    AInteractableBase();

    UPROPERTY(EditAnywhere)
    bool State;

    //Bool value is inversion - so default false.
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TSet<ATriggerableBase*> Inverted = TSet<ATriggerableBase*>();
    
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<ATriggerableBase*> Triggerables = TArray<ATriggerableBase*>();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

    //Link this interactable to a triggerable
    UFUNCTION(BlueprintCallable)
    void LinkTriggerables();

    //Change between on/off, may need adjusting down the line
    UFUNCTION(BlueprintCallable)
    void ToggleState();

    //Sets state of the interactable
    UFUNCTION(BlueprintCallable)
    void SetState(bool newState);

    //Returns the current state of this interactible
    UFUNCTION(BlueprintCallable)
    bool GetState();

};
