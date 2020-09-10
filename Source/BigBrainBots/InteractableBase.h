// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
    //Change between on/off, may need adjusting down the line
    void ToggleState();
    
    //Sets state of the interactable
    void SetState(bool newState);
    
    //Returns the current state of this interactible
    bool GetState();
	
};
