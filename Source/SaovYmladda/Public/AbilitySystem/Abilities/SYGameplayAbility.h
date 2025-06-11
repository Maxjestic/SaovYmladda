// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "SYGameplayAbility.generated.h"

/**
 * The base class for all Gameplay Abilities in SaovYmladda.
 */
UCLASS( Blueprintable, Abstract )
class SAOVYMLADDA_API USYGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

protected:
	UFUNCTION( BlueprintCallable, Category = "AbilitySystem" )
	FGameplayTag GetAbilityTag() const;

};
