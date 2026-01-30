#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/Character.h"
#include "HCTCharacter_2D.generated.h"

class UInputAction;

UCLASS()
class HOICHOTET26_API AHCTCharacter_2D : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHCTCharacter_2D();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputAction* MoveInputAction;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
private:
	void Move(const FInputActionValue& Value);
};
