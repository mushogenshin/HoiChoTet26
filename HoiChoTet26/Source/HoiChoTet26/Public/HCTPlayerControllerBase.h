// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "HCTPlayerControllerBase.generated.h"

class UInputAction;
class UInputMappingContext;



/**
 * 
 */
UCLASS()
class HOICHOTET26_API AHCTPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
	AHCTPlayerControllerBase();
	
public:
	virtual void BeginPlay() override;
	
protected:
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputMappingContext* DefaultInputSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputAction* LookInputAction;
	
private:
	void Look(const FInputActionValue& Value);
};
