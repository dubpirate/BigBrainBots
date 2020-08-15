// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BotParent.generated.h"

UCLASS()
class BIGBRAINBOTS_API ABotParent : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABotParent();

	UPROPERTY(BlueprintReadWrite, category="Stats")
	int Health;

	UPROPERTY(BlueprintReadWrite, category="Stats")
	int Speed;

	UPROPERTY(BlueprintReadWrite, category="Stats")
	float Gas_Multiplier;

	UPROPERTY(BlueprintReadOnly, category = "Stats")
	FString Bot_Name; //todo check if fstring is appropriate

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
