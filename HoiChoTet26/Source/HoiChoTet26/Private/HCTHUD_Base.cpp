// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTet26/Public/HCTHUD_Base.h"

AHCTHUD_Base::AHCTHUD_Base()
{
}

void AHCTHUD_Base::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai HUD HoiChoTet"));
}
