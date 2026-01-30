// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "HCTPawnBase.generated.h"

class UInputAction;
class UFloatingPawnMovement;
struct FInputActionValue;

UCLASS()
class HOICHOTET26_API AHCTPawnBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AHCTPawnBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFloatingPawnMovement* MovementComponent;

	// UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// float MoveSpeed = 600.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputAction* MoveInputAction;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;
	
private:
	void Move(const FInputActionValue& Value);
};
