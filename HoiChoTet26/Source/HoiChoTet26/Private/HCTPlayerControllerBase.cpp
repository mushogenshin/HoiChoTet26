// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTet26/Public/HCTPlayerControllerBase.h"

AHCTPlayerControllerBase::AHCTPlayerControllerBase()
{
}

void AHCTPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai Player Controller HoiChoTet"));
}
