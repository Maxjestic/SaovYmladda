// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Core/SYGameMode.h"

#include "Characters/Player/SYPlayerCharacter.h"
#include "Player/SYHUD.h"
#include "Player/SYPlayerController.h"
#include "Player/SYPlayerState.h"

ASYGameMode::ASYGameMode()
{
	PlayerControllerClass = ASYPlayerController::StaticClass();
	DefaultPawnClass = ASYPlayerCharacter::StaticClass();
	HUDClass = ASYHUD::StaticClass();
	PlayerStateClass = ASYPlayerState::StaticClass();
}
