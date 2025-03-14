// Copyright Epic Games, Inc. All Rights Reserved.

#include "WitchHammerGameMode.h"

#include <string>

#include "UObject/ConstructorHelpers.h"
#include "WitchHammer/WitchHammerCharacter.h"
#include "WitchHammer/WitchHammerPlayerController.h"
#include "Logging/LogMacros.h"
#include "Kismet/GameplayStatics.h"

AWitchHammerGameMode::AWitchHammerGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWitchHammerPlayerController::StaticClass();
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}


void AWitchHammerGameMode::BeginPlay()
{
	Super::BeginPlay();
}
