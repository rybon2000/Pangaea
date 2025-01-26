

#include "PangaeaGameMode.h"
#include "PangaeaPlayerController.h"
#include "PangaeaCharacter.h"
#include "UObject/ConstructorHelpers.h"

APangaeaGameMode::APangaeaGameMode()
{
	
	PlayerControllerClass = APangaeaPlayerController::StaticClass();


	 static ConstructorHelpers::FClassFinder<APawn>
 PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
 if (PlayerPawnBPClass.Class != nullptr)
 {
 DefaultPawnClass = PlayerPawnBPClass.Class;
 }
}