// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "SYAbilityAnimationDataAsset.generated.h"

/**
 * The Data Asset class to store Animations played by Abilities.
 * Every type of character should have its own Data Asset with proper animations set.
 */
UCLASS( BlueprintType )
class SAOVYMLADDA_API USYAbilityAnimationDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	/**
	 * A map of Gameplay Tags to Animation Montages
	 * The Gameplay Ability uses its own Ability Tag to find the correct montage to play.
	 */
	UPROPERTY( BlueprintReadOnly, EditDefaultsOnly, Category = "Animation", meta=(ForceInlineRow) )
	TMap<FGameplayTag, TObjectPtr<UAnimMontage>> AbilityAnimations;
};
