#pragma once

#include "CoreMinimal.h"
#include "InputActionValue.h"
#include "GameFramework/PlayerController.h"
#include "HCTPlayerControllerBase.generated.h"

class UInputAction;
class UInputMappingContext;
class AHCTPawnBase;

/**
 * 
 */
UCLASS()
class HOICHOTET26_API AHCTPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
	AHCTPlayerControllerBase();
	
public:
	virtual void BeginPlay() override;
	
protected:
	virtual void SetupInputComponent() override;
	
	virtual void AcknowledgePossession(APawn* P) override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputMappingContext* DefaultInputSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputAction* LookInputAction;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "HoiChoTet|Input")
	UInputAction* EjectGameInputAction;

	// Reference to the original pawn to repossess after ejecting
	UPROPERTY()
	AHCTPawnBase* OriginalPawn;
	
private:
	void Look(const FInputActionValue& Value);
	void EjectGame();
	void AddDefaultInputMappingCtx(bool Clear=false) const;
};
