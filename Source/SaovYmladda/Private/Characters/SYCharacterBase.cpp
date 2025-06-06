// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Characters/SYCharacterBase.h"

#include "AbilitySystem/SYAbilitySystemComponent.h"
#include "AbilitySystem/SYAttributeSet.h"

ASYCharacterBase::ASYCharacterBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<USYAbilitySystemComponent>( "AbilitySystemComponent" );
	AbilitySystemComponent->SetIsReplicated( true );
	AbilitySystemComponent->SetReplicationMode( EGameplayEffectReplicationMode::Minimal );

	AttributeSet = CreateDefaultSubobject<USYAttributeSet>( "AttributeSet" );
}

UAbilitySystemComponent* ASYCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
