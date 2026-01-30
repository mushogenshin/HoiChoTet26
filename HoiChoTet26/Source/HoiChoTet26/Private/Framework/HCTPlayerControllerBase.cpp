#include "Framework/HCTPlayerControllerBase.h"
#include "Framework/HCTPawnBase.h"
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
	AddDefaultInputMappingCtx();
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
		
		// Bind the eject game action
		if (EjectGameInputAction){
			EnhancedInputComponent->BindAction(EjectGameInputAction, ETriggerEvent::Triggered, this, &AHCTPlayerControllerBase::EjectGame);
		}
	}
}

void AHCTPlayerControllerBase::AcknowledgePossession(APawn* P)
{
	Super::AcknowledgePossession(P);
	
	// Store reference to the first HCTPawnBase we possess
	// ReSharper disable once CppUE4CodingStandardNamingViolationWarning
	if (AHCTPawnBase* HCTPawn = Cast<AHCTPawnBase>(P); HCTPawn && !OriginalPawn)
	{
		OriginalPawn = HCTPawn;
		UE_LOG(LogTemp, Warning, TEXT("AcknowledgePossession: Stored reference to original pawn %s"), *OriginalPawn->GetName());
	}
}

void AHCTPlayerControllerBase::Look(const FInputActionValue& Value)
{
	const FVector2D LookAxis = Value.Get<FVector2D>();
	// NOTE: on the Pawn, bUseControllerRotationYaw must be true to 
	// allow controller rotation to affect the pawn's camera
	AddYawInput(LookAxis.X);
	AddPitchInput(LookAxis.Y);
}

void AHCTPlayerControllerBase::EjectGame()
{
	if (OriginalPawn && GetPawn() == OriginalPawn)
	{
		UE_LOG(LogTemp, Warning, TEXT("EjectGame: Already possessing the original pawn."));
		return;
	}
	
	// Unpossess current pawn from the mini-game
	UnPossess();
	
	// Restore input mapping context
	AddDefaultInputMappingCtx(true);
	
	// Try repossessing the original pawn 
	if (OriginalPawn)
	{
		Possess(OriginalPawn);
	}
}


void AHCTPlayerControllerBase::AddDefaultInputMappingCtx(const bool Clear) const
{
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		if (Clear)
		{
			Subsystem->ClearAllMappings();
		}
		if (DefaultInputSet)
		{
			Subsystem->AddMappingContext(DefaultInputSet, 0);
		}
	}
}
