// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "OverlayWidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;
class ASYPlayerState;
class USYAbilitySystemComponent;
class USYAttributeSet;


/**
 * A struct used to initialize Widget Controller with Models.
 * Models: Ability System Component, Attribute Set
 */
USTRUCT( BlueprintType )
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams()
	{
	}

	FWidgetControllerParams( UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet )
		: AbilitySystemComponent( AbilitySystemComponent ), AttributeSet( AttributeSet )
	{
	}

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;

	UPROPERTY( EditAnywhere, BlueprintReadWrite )
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
};


/** Used to broadcast Attribute changes to View */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam( FOnAttributeChangedSignature, float, NewValue );


/**
 * The Widget Controller class for the Overlay.
 * Listens to changes in Attributes and broadcasts them to the View.
 */
UCLASS( Blueprintable, BlueprintType )
class SAOVYMLADDA_API UOverlayWidgetController : public UObject
{
	GENERATED_BODY()

public:
	/** Sets all models for Widget Controller */
	void SetWidgetControllerParams( const FWidgetControllerParams& WidgetControllerParams );

	/** Broadcasts initial values to set up Widgets correctly */
	void BroadcastInitialValues() const;

	/**
	 * Binds lambda functions to Model delegates.
	 * Changes are broadcaster further to View.
	 */
	void BindCallbacksToDelegates() const;

	/** ---Delegates for Attribute changes--- **/

	UPROPERTY( BlueprintAssignable, Category="GAS|Events" )
	FOnAttributeChangedSignature OnMaxHealthChanged;

	UPROPERTY( BlueprintAssignable, Category="GAS|Events" )
	FOnAttributeChangedSignature OnHealthChanged;

	UPROPERTY( BlueprintAssignable, Category="GAS|Events" )
	FOnAttributeChangedSignature OnMaxStaminaChanged;

	UPROPERTY( BlueprintAssignable, Category="GAS|Events" )
	FOnAttributeChangedSignature OnStaminaChanged;

protected:

	/** Widget's owner Ability System Component. */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Model" )
	TObjectPtr<USYAbilitySystemComponent> SYAbilitySystemComponent;

	/** Widget's owner Attribute Set. */
	UPROPERTY( EditAnywhere, BlueprintReadWrite, Category="Model" )
	TObjectPtr<USYAttributeSet> SYAttributeSet;
};
