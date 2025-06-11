// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "AbilitySystem/Abilities/SYGameplayAbility.h"

FGameplayTag USYGameplayAbility::GetAbilityTag() const
{
	return GetAssetTags().GetByIndex( 0 );
}
