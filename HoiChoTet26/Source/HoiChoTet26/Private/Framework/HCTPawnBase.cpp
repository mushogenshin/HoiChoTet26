// Fill out your copyright notice in the Description page of Project Settings.

#include "Framework/HCTPawnBase.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/SphereComponent.h"


// Sets default values
AHCTPawnBase::AHCTPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Enable rotation to follow the controller
	bUseControllerRotationYaw = true;

	// Create collision component as root
	USphereComponent* CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CollisionComponent"));
	SetRootComponent(CollisionComponent);
	CollisionComponent->InitSphereRadius(50.0f);
	CollisionComponent->SetCollisionProfileName(TEXT("Pawn"));
	CollisionComponent->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	CollisionComponent->SetCollisionResponseToChannel(ECC_WorldDynamic, ECR_Overlap);
	CollisionComponent->SetGenerateOverlapEvents(true);

	// FloatingPawnMovement automatically handles ConsumeMovementInputVector
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
	MovementComponent->UpdatedComponent = CollisionComponent;
}

// Called when the game starts or when spawned
void AHCTPawnBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai Pawn HoiChoTet"));
}

// Called every frame
void AHCTPawnBase::Tick(const float DeltaTime)
{
	Super::Tick(DeltaTime);

	// // If NOT using FloatingPawnMovement, manually consume input:
	// FVector Input = ConsumeMovementInputVector();
	// AddActorWorldOffset(Input * MoveSpeed * DeltaTime, true);
}

// Called to bind functionality to input
void AHCTPawnBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent))
	{
		// Bind the movement action
		if (MoveInputAction)
		{
			EnhancedInputComponent->BindAction(MoveInputAction, ETriggerEvent::Triggered, this,
			                                   &AHCTPawnBase::Move);
		}
	}
}

void AHCTPawnBase::Move(const FInputActionValue& Value)
{
	const FVector2D Movement = Value.Get<FVector2D>();
	AddMovementInput(GetActorForwardVector(), Movement.Y);
	AddMovementInput(GetActorRightVector(), Movement.X);
}
