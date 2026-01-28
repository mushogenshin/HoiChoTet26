// Fill out your copyright notice in the Description page of Project Settings.

#include "HoiChoTet26/Public/HCTPawnBase.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AHCTPawnBase::AHCTPawnBase()
{
	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// FloatingPawnMovement automatically handles ConsumeMovementInputVector
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("MovementComponent"));
}

// Called when the game starts or when spawned
void AHCTPawnBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai Pawn HoiChoTet"));
}

// Called every frame
void AHCTPawnBase::Tick(float DeltaTime)
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
}

