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

bool USYAbilitySystemComponent::TryActivateAbilityByGameplayTag( const FGameplayTag& GameplayTag )
{
	//TODO: It should be made using AbilityInputPressed method
	const FGameplayTagContainer GameplayTags( GameplayTag );
	if (!TryActivateAbilitiesByTag( GameplayTags ))
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage( 1, 2, FColor::Yellow, "Failed to activate ability with tag" + GameplayTag.ToString() );			
		}
		return false;
	}
	return true;
}
