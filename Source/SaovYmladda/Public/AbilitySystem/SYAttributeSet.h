// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "SYAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * The project-specific Attribute Set for SaovYmladda.
 *
 * Defines the set of core attributes for characters.
 * This class holds attributes like Health, Stamina, etc., which are managed by the Gameplay Ability System.
 */
UCLASS()
class SAOVYMLADDA_API USYAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	//~ Begin UObject Interface
	/**
	 * Allows for NetMulticast-capable properties to be replicated over the network.
	 * This is where you list all attributes that need to be synced from server to client.
	 */
	virtual void GetLifetimeReplicatedProps( TArray<FLifetimeProperty>& OutLifetimeProps ) const override;
	//~ End UObject Interface
	

	//~ Begin UAttributeSet Interface

	/** Handles minimum and maximum values before changing attributes */
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;

	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	//~ End UAttributeSet Interface
	

	/** The character's Max Health. */
	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Attributes" )
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS( USYAttributeSet, MaxHealth )

	/** The character's current Health. */
	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes" )
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS( USYAttributeSet, Health )

	/** The character's Max Stamina. */
	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_MaxStamina, Category = "Attributes" )
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS( USYAttributeSet, MaxStamina )

	/** The character's current Stamina. */
	UPROPERTY( BlueprintReadOnly, ReplicatedUsing = OnRep_Stamina, Category = "Attributes" )
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS( USYAttributeSet, Stamina )

protected:
	/**
	 * The functions below are called on clients when the attribute is replicated.
	 */

	UFUNCTION()
	void OnRep_MaxHealth( const FGameplayAttributeData& OldMaxHealth ) const;

	UFUNCTION()
	void OnRep_Health( const FGameplayAttributeData& OldHealth ) const;

	UFUNCTION()
	void OnRep_MaxStamina( const FGameplayAttributeData& OldMaxStamina ) const;

	UFUNCTION()
	void OnRep_Stamina( const FGameplayAttributeData& OldStamina ) const;
};
