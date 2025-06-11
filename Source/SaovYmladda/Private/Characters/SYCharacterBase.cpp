// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Characters/SYCharacterBase.h"

#include "AbilitySystem/SYAbilitySystemComponent.h"
#include "AbilitySystem/SYAttributeSet.h"
#include "Data/SYAbilityAnimationDataAsset.h"

ASYCharacterBase::ASYCharacterBase()
{
}

UAbilitySystemComponent* ASYCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}

UAnimMontage* ASYCharacterBase::GetAnimMontageForTag_Implementation( const FGameplayTag Key )
{
	if ( AbilityAnimationsData )
	{
		return AbilityAnimationsData->AbilityAnimations.FindRef( Key );
	}
	return nullptr;
}

void ASYCharacterBase::ApplyEffectToSelf( const TSubclassOf<UGameplayEffect>& GameplayEffectClass,
                                          const float Level ) const
{
	ensureMsgf( IsValid(GetAbilitySystemComponent()), TEXT("ASYCharacterBase::ApplyEffectToSelf - ASC not valid") );
	ensureMsgf( GameplayEffectClass, TEXT("ASYCharacterBase::ApplyEffectToSelf - GameplayEffectClass not valid") );

	FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
	ContextHandle.AddSourceObject( this );
	const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(
		GameplayEffectClass,
		Level,
		ContextHandle );
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget( *SpecHandle.Data.Get(), GetAbilitySystemComponent() );
}

void ASYCharacterBase::InitializeAbilityActorInfo()
{
	ensureMsgf( false, TEXT("InitializeAbilityActorInfo() must be implemented in the derived class. It was not.") );
}

void ASYCharacterBase::InitializeDefaultAttributes() const
{
	ensureMsgf( false, TEXT("InitializeAbilityActorInfo() must be implemented in the derived class. It was not.") );
}

void ASYCharacterBase::AddDefaultAbilities() const
{
	if ( !HasAuthority() ) return;

	USYAbilitySystemComponent* AuraAbilitySystemComponent = CastChecked<USYAbilitySystemComponent>(
		AbilitySystemComponent );
	AuraAbilitySystemComponent->AddDefaultAbilities( DefaultAbilities );
}
