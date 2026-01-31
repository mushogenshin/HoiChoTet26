#include "Framework/HCTGameModeBase.h"
#include "Framework/HCTHUD_Base.h"
#include "Framework/HCTPawnBase.h"
#include "Framework/HCTPlayerControllerBase.h"

AHCTGameModeBase::AHCTGameModeBase()
{
	// Set default classes
	PlayerControllerClass = AHCTPlayerControllerBase::StaticClass();
	DefaultPawnClass = AHCTPawnBase::StaticClass();
	HUDClass = AHCTHUD_Base::StaticClass();
}

void AHCTGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Bat dau xai Game Mode HoiChoTet"));
}
