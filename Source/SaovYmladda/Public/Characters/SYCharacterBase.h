// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "SYCharacterBase.generated.h"

class UGameplayAbility;
class UGameplayEffect;
class USYAttributeSet;
class USYAbilitySystemComponent;

/**
 * The base class for all characters in SaovYmladda.
 * It's designed to be subclassed by player and enemy characters.
 * Implements the IAbilitySystemInterface to work with the Gameplay Ability System.
 */
UCLASS( Abstract, Blueprintable )
class SAOVYMLADDA_API ASYCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	/**
	 * Default Constructor.
	 * Sets up AbilitySystemComponent and AttributeSet.
	 */
	ASYCharacterBase();


	//~ Begin IAbilitySystemInterface
	/**
	 * AbilitySystemComponent Getter.
	 * @return A pointer to this character's AbilitySystemComponent.
	 */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	//~ End IAbilitySystemInterface

	//~ Begin APawn Interface
	virtual void PossessedBy( AController* NewController ) override;
	//~ End APawn Interface

protected:
	/**
	 * Applies given effect to self 
	 * @param GameplayEffectClass Class of the Effect to apply
	 * @param Level Level for the effect
	 */
	void ApplyEffectToSelf( const TSubclassOf<UGameplayEffect>& GameplayEffectClass, const float Level = 1.f ) const;

	/** Initializes default attributes when the game starts */
	void InitializeDefaultAttributes() const;

	/**
	 * The character's Ability System Component. 
	 * Responsible for handling abilities and gameplay effects.
	 */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = "Abilities" )
	TObjectPtr<USYAbilitySystemComponent> AbilitySystemComponent;

	/**
	 * The character's Attribute Set.
	 * Contains attributes like Health, Stamina, etc.
	 */
	UPROPERTY()
	TObjectPtr<USYAttributeSet> AttributeSet;

	/** A list of abilities to grant to this character on startup. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities" )
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	/** The Gameplay Effect to apply for initializing primary attributes. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities" )
	TSubclassOf<UGameplayEffect> PrimaryAttributesEffect;

	/** The Gameplay Effect to apply for initializing vital attributes. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities" )
	TSubclassOf<UGameplayEffect> VitalAttributesEffect;
};
