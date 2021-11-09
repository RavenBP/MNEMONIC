// Copyright Epic Games, Inc. All Rights Reserved.

#include "MNEMONIC_ProjectGameMode.h"
#include "MNEMONIC_ProjectHUD.h"
#include "MNEMONIC_ProjectCharacter.h"
#include "UObject/ConstructorHelpers.h"

AMNEMONIC_ProjectGameMode::AMNEMONIC_ProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AMNEMONIC_ProjectHUD::StaticClass();
}
