// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "SYAssetManager.generated.h"

/**
 * The project-specific Asset Manager for SaovYmladda.
 *
 * This class serves as the Asset Manager class defined in the DefaultEngine.ini.
 * Main purpose - Initialization of native Gameplay Tags.
 */
UCLASS()
class SAOVYMLADDA_API USYAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	/** Return the current Asset Manager object */
	static USYAssetManager& Get();

protected:
	//~ Begin UAssetManager Interface

	/** Initializes Gameplay Tags */
	virtual void StartInitialLoading() override;

	//~ Begin UAssetManager Interface
};
