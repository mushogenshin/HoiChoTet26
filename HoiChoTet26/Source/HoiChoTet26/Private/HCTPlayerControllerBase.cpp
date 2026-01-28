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
	
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (DefaultInputSet)
		{
			// Add the mapping context with priority 0 (default)
			Subsystem->AddMappingContext(DefaultInputSet, 0);
		}
	}
}

void AHCTPlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind the movement action
		if (MoveInputAction){
			EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this, &AHCTPlayerControllerBase::Move);
		}
	}
}

void AHCTPlayerControllerBase::Move(const FInputActionValue& InputActionValue)
{
	UE_LOG(LogTemp, Warning, TEXT("TODO: implement Move possessed pawn"));
}
