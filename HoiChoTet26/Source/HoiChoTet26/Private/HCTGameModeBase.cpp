// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTet26/Public/HCTGameModeBase.h"

AHCTGameModeBase::AHCTGameModeBase()
{
}

void AHCTGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai Game Mode HoiChoTet"));
}
