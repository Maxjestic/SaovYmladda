// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "UI/WidgetControllers/OverlayWidgetController.h"

#include "AbilitySystem/SYAbilitySystemComponent.h"
#include "AbilitySystem/SYAttributeSet.h"

void UOverlayWidgetController::SetWidgetControllerParams( const FWidgetControllerParams& WidgetControllerParams )
{
	SYAbilitySystemComponent = Cast<USYAbilitySystemComponent>( WidgetControllerParams.AbilitySystemComponent );
	SYAttributeSet = Cast<USYAttributeSet>( WidgetControllerParams.AttributeSet );
}

void UOverlayWidgetController::BroadcastInitialValues() const
{
	OnMaxHealthChanged.Broadcast( SYAttributeSet->GetMaxHealth() );
	OnHealthChanged.Broadcast( SYAttributeSet->GetHealth() );
	OnMaxStaminaChanged.Broadcast( SYAttributeSet->GetMaxStamina() );
	OnStaminaChanged.Broadcast( SYAttributeSet->GetStamina() );
}

void UOverlayWidgetController::BindCallbacksToDelegates() const
{
	SYAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SYAttributeSet->GetMaxHealthAttribute() ).AddLambda(
		[this]( const FOnAttributeChangeData& Data )
		{
			OnMaxHealthChanged.Broadcast( Data.NewValue );
		}
	);

	SYAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SYAttributeSet->GetHealthAttribute() ).AddLambda(
		[this]( const FOnAttributeChangeData& Data )
		{
			OnHealthChanged.Broadcast( Data.NewValue );
		}
	);

	SYAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SYAttributeSet->GetMaxStaminaAttribute() ).AddLambda(
		[this]( const FOnAttributeChangeData& Data )
		{
			OnMaxStaminaChanged.Broadcast( Data.NewValue );
		}
	);

	SYAbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(
		SYAttributeSet->GetStaminaAttribute() ).AddLambda(
		[this]( const FOnAttributeChangeData& Data )
		{
			OnStaminaChanged.Broadcast( Data.NewValue );
		}
	);
}
