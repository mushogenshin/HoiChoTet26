#include "MiniGames/HCTCharacter_2D.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
AHCTCharacter_2D::AHCTCharacter_2D()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// bUseControllerRotationYaw and bUseControllerRotationPitch are false by default for ACharacter
	
	// ReSharper disable once CppUE4CodingStandardNamingViolationWarning
	if (UCharacterMovementComponent* CMC = GetCharacterMovement())
	{
		// General Settings
		CMC->MaxAcceleration = 512.0f;

		// Walking
		CMC->MaxStepHeight = 5.0f;
		CMC->MaxWalkSpeed = 200.0f;
		CMC->MaxWalkSpeedCrouched = 100.0f;

		// Jumping/Falling
		CMC->JumpZVelocity = 300.0f;

		// Swimming
		CMC->MaxSwimSpeed = 50.0f;

		// Flying
		CMC->MaxFlySpeed = 150.0f;

		// Custom Movement
		CMC->MaxCustomMovementSpeed = 200.0f;
	}
}

// Called when the game starts or when spawned
void AHCTCharacter_2D::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AHCTCharacter_2D::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AHCTCharacter_2D::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind the movement action
		if (MoveInputAction)
		{
			EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this,
											   &AHCTCharacter_2D::Move);
		}
	}
}

void AHCTCharacter_2D::Move(const FInputActionValue& Value)
{
	const FVector2D Movement = Value.Get<FVector2D>();
	// Only move sideways
	AddMovementInput(GetActorRightVector(), Movement.X);
}

