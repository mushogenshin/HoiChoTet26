// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "HCTHUD_Base.generated.h"

/**
 * 
 */
UCLASS()
class HOICHOTET26_API AHCTHUD_Base : public AHUD
{
	GENERATED_BODY()
	
	AHCTHUD_Base();
	
public:
	virtual void BeginPlay() override;
};
