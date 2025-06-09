// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Player/SYPlayerState.h"

#include "AbilitySystem/SYAbilitySystemComponent.h"
#include "AbilitySystem/SYAttributeSet.h"

ASYPlayerState::ASYPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<USYAbilitySystemComponent>( TEXT( "AbilitySystemComponent" ) );
	AbilitySystemComponent->SetIsReplicated( true );
	AbilitySystemComponent->SetReplicationMode( EGameplayEffectReplicationMode::Minimal );

	AttributeSet = CreateDefaultSubobject<USYAttributeSet>( TEXT( "AttributeSet" ) );
}

UAbilitySystemComponent* ASYPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
