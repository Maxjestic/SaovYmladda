// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/Interface.h"
#include "AbilityAnimationProviderInterface.generated.h"

class USYAbilityAnimationDataAsset;

// This class does not need to be modified.
UINTERFACE( MinimalAPI )
class UAbilityAnimationProviderInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * Interface for any actor that can provide the Ability Animation Data Asset.
 */
class SAOVYMLADDA_API IAbilityAnimationProviderInterface
{
	GENERATED_BODY()

public:
	/**
	 * Finds and returns the Anim Montage associated with a given Ability Gameplay Tag.
	 * @param Key Gameplay Tag associated with Ability and Animation
	 * @return The found AnimMontage, or nullptr if not found. 
	 */
	UFUNCTION( BlueprintNativeEvent, BlueprintCallable, Category = "Animation" )
	UAnimMontage* GetAnimMontageForTag( FGameplayTag Key );
};
