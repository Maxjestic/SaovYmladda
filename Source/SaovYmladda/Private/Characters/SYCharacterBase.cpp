// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Characters/SYCharacterBase.h"

#include "AbilitySystem/SYAbilitySystemComponent.h"
#include "AbilitySystem/SYAttributeSet.h"

ASYCharacterBase::ASYCharacterBase()
{
	AbilitySystemComponent = CreateDefaultSubobject<USYAbilitySystemComponent>( TEXT( "AbilitySystemComponent" ) );
	AbilitySystemComponent->SetIsReplicated( true );
	AbilitySystemComponent->SetReplicationMode( EGameplayEffectReplicationMode::Minimal );

	AttributeSet = CreateDefaultSubobject<USYAttributeSet>( TEXT( "AttributeSet" ) );
}

UAbilitySystemComponent* ASYCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

void ASYCharacterBase::PossessedBy( AController* NewController )
{
	Super::PossessedBy( NewController );

	if ( !HasAuthority() )
	{
		return;
	}

	InitializeDefaultAttributes();
}

void ASYCharacterBase::ApplyEffectToSelf( const TSubclassOf<UGameplayEffect>& GameplayEffectClass,
                                          const float Level ) const
{
	check( IsValid(GetAbilitySystemComponent()) );
	check( GameplayEffectClass );

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject( this );
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(
		GameplayEffectClass,
		Level,
		ContextHandle );
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget( *SpecHandle.Data.Get(), GetAbilitySystemComponent() );
}

void ASYCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf( PrimaryAttributesEffect );
	ApplyEffectToSelf( VitalAttributesEffect );
}
