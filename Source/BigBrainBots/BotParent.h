// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/Actor.h"
#include "BotParent.generated.h"

UCLASS()
class BIGBRAINBOTS_API ABotParent : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABotParent();

	UPROPERTY(BlueprintReadWrite, category="Stats")
	float Max_Health;

	UPROPERTY(BlueprintReadWrite, category="Stats")
	float Health;

	UPROPERTY(BlueprintReadWrite, category="Stats")
	float Speed;

	UPROPERTY(BlueprintReadWrite, category="Stats")
	float Gas_Multiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "CharacterSwitching")
	ABotParent* Next_Bot;

	/** Top down camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;

	/** Camera boom positioning the camera above the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;

	// Todo: May not be completely necessary because of the name of the 
	UPROPERTY(BlueprintReadOnly, category = "Stats")
	FString Bot_Name; //todo check if fstring is appropriate

	// Updates the health variable.
	UFUNCTION(BlueprintCallable)
	void ModifyHealth(float deltaHealth);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void FellOutOfWorld(const class UDamageType & dmgType) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
};