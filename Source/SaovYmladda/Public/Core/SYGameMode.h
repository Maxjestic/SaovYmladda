// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SYGameMode.generated.h"

/**
 * The project-specific Game Mode for SaovYmladda.
 *
 * This class serves as the base for Game Mode.
 */
UCLASS( Blueprintable, Abstract )
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
