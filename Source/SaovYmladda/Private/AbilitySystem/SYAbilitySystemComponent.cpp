// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "AbilitySystem/SYAbilitySystemComponent.h"

#include "AbilitySystem/Abilities/SYGameplayAbility.h"

void USYAbilitySystemComponent::AddDefaultAbilities( const TArray<TSubclassOf<UGameplayAbility>>& DefaultAbilities )
{
	for ( const TSubclassOf AbilityClass : DefaultAbilities )
	{
		FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec( AbilityClass, 1 );
		GiveAbility( AbilitySpec );
	}
}
