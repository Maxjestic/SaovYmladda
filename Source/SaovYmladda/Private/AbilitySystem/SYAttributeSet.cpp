// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "AbilitySystem/SYAttributeSet.h"

#include "Net/UnrealNetwork.h"

void USYAttributeSet::GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const
{
	Super::GetLifetimeReplicatedProps( OutLifetimeProps );

	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always )
	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, Health, COND_None, REPNOTIFY_Always )
	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, MaxStamina, COND_None, REPNOTIFY_Always )
	DOREPLIFETIME_CONDITION_NOTIFY( USYAttributeSet, Stamina, COND_None, REPNOTIFY_Always )
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
