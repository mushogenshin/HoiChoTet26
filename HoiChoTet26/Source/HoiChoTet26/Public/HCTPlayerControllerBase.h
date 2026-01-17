// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "HCTPlayerControllerBase.generated.h"

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
};
