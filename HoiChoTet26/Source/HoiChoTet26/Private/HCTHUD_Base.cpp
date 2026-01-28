// Fill out your copyright notice in the Description page of Project Settings.


#include "HoiChoTet26/Public/HCTHUD_Base.h"

AHCTHUD_Base::AHCTHUD_Base()
{
}

void AHCTHUD_Base::BeginPlay()
{
	Super::BeginPlay();
	
	if (ClassCuaTamPhong)
	{
		WidgetInstance = CreateWidget<UUserWidget>(GetOwningPlayerController(), ClassCuaTamPhong);
		if (WidgetInstance)
		{
			WidgetInstance->AddToViewport();
		}
	}
}
