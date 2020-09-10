// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InteractableBase.h"
#include "PressurePlate.generated.h"

/**
 * 
 */
UCLASS()
class BIGBRAINBOTS_API APressurePlate : public AInteractableBase
{
	GENERATED_BODY()
	
	void Tick(float DeltaTime) override;
	
	
};
