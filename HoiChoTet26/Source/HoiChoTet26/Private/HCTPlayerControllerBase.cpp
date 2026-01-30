// Fill out your copyright notice in the Description page of Project Settings.

#include "HoiChoTet26/Public/HCTPlayerControllerBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

AHCTPlayerControllerBase::AHCTPlayerControllerBase()
{
}

void AHCTPlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai Player Controller HoiChoTet"));
	
	// Add the mapping context 
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultInputSet)
		{
			Subsystem->AddMappingContext(DefaultInputSet, 0);
		}
	}
}

void AHCTPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind the look action
		if (LookInputAction){
			EnhancedInputComponent->BindAction(LookInputAction, ETriggerEvent::Triggered, this, &AHCTPlayerControllerBase::Look);
		}	
	}
}

void AHCTPlayerControllerBase::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();
	AddYawInput(LookAxis.X);
	AddPitchInput(LookAxis.Y);
}
