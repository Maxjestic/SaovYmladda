// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "AbilitySystem/SYAttributeSet.h"
#include "GameplayEffectExtension.h"

#include "Net/UnrealNetwork.h"

void USYAttributeSet::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );

	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always )
	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, Health, COND_None, REPNOTIFY_Always )
	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always )
	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, Stamina, COND_None, REPNOTIFY_Always )
}

void USYAttributeSet::PreAttributeChange( const FGameplayAttribute& Attribute, float& NewValue )
{
	Super::PreAttributeChange( Attribute, NewValue );
	if ( Attribute == GetHealthAttribute() )
	{
		NewValue = FMath::Clamp( NewValue, 0.f, GetMaxHealth() );
	}
	if ( Attribute == GetStaminaAttribute() )
	{
		NewValue = FMath::Clamp( NewValue, 0.f, GetMaxStamina() );
	}
}

void USYAttributeSet::PostGameplayEffectExecute( const struct FGameplayEffectModCallbackData& Data )
{
	Super::PostGameplayEffectExecute( Data );

	if (Data.EvaluatedData.Attribute == GetStaminaAttribute())
	{
		SetStamina( FMath::Clamp( GetStamina(), 0.f, GetMaxStamina() ) );
	}

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth( FMath::Clamp( GetHealth(), 0.f, GetMaxHealth() ) );
	}
}

void USYAttributeSet::OnRep_MaxHealth( const FGameplayAttributeData& OldMaxHealth ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY( USYAttributeSet, MaxHealth, OldMaxHealth )
}

void USYAttributeSet::OnRep_Health( const FGameplayAttributeData& OldHealth ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY( USYAttributeSet, Health, OldHealth )
}

void USYAttributeSet::OnRep_MaxStamina( const FGameplayAttributeData& OldMaxStamina ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY( USYAttributeSet, MaxStamina, OldMaxStamina )
}

void USYAttributeSet::OnRep_Stamina( const FGameplayAttributeData& OldStamina ) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY( USYAttributeSet, Stamina, OldStamina )
}
