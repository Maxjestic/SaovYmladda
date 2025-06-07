// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SYGameMode.generated.h"

/**
 * The main GameMode for the SaovYmladda project.
 * It inherits from the lightweight AGameModeBase and is responsible for defining the
 * core rules and default classes for the game, such as the Player Controller and Pawn.
 */
UCLASS( Abstract, Blueprintable )
class SAOVYMLADDA_API ASYGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	/**
	 * Default constructor.
	 * Sets the default C++ abstract classes as a reminder to set proper Blueprints.
	 */
	ASYGameMode();
};
