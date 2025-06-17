// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "Interfaces/AbilityAnimationProviderInterface.h"
#include "SYCharacterBase.generated.h"

class USYAbilityAnimationDataAsset;
class UAttributeSet;
class UGameplayAbility;
class UGameplayEffect;
class USYAttributeSet;
class USYAbilitySystemComponent;

/**
 * The base class for all Characters in SaovYmladda.
 * 
 * It's designed to be subclassed by other Characters.
 * It promises the setup for Gameplay Ability System like initialization of Attributes and Abilities.
 * Implements the IAbilitySystemInterface to work with the Gameplay Ability System.
 */
UCLASS( Blueprintable, Abstract )
class SAOVYMLADDA_API ASYCharacterBase : public ACharacter, public IAbilitySystemInterface,
                                         public IAbilityAnimationProviderInterface
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


	//~ Begin IAbilityAnimationProviderInterface

	virtual UAnimMontage* GetAnimMontageForTag_Implementation(const FGameplayTag Key) override;

	//~ End IAbilityAnimationProviderInterface

protected:
	/**
	 * Applies given effect to self 
	 * @param GameplayEffectClass Class of the Effect to apply
	 * @param Level Level for the effect
	 */
	void ApplyEffectToSelf( const TSubclassOf<UGameplayEffect>& GameplayEffectClass, const float Level = 1.f ) const;

	/** Initializes ASC and AS when the game starts */
	virtual void InitializeAbilityActorInfo();

	/** Initializes default attributes when the game starts */
	virtual void InitializeDefaultAttributes() const;

	/** Adds default abilities when the game starts */
	void AddDefaultAbilities() const;

	/**
	 * The character's Ability System Component. 
	 * Responsible for handling abilities and gameplay effects.
	 * For PlayerCharacter it exists in PlayerState.
	 * For AI Characters it exists directly on the Character.
	 */
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Abilities" )
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	/**
	 * The character's Attribute Set.
	 * Contains attributes like Health, Stamina, etc.
	 * For PlayerCharacter, it exists on PlayerState.
	 * For AI Characters it exists directly on the Character.
	 */
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

	/** A list of abilities to grant to this character on startup. */
	UPROPERTY( BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities" )
	TArray<TSubclassOf<UGameplayAbility>> DefaultAbilities;

	/** The Gameplay Effect to apply for initializing primary attributes. */
	UPROPERTY( BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities" )
	TSubclassOf<UGameplayEffect> PrimaryAttributesEffect;

	/** The Gameplay Effect to apply for initializing vital attributes. */
	UPROPERTY( BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities" )
	TSubclassOf<UGameplayEffect> VitalAttributesEffect;

	/** The Gameplay Effect to apply for stamina regeneration. */
	UPROPERTY( BlueprintReadOnly, EditDefaultsOnly, Category = "Abilities" )
	TSubclassOf<UGameplayEffect> StaminaRegenEffect;

	/** Data asset containing references to ability-specific animations. */
	UPROPERTY( BlueprintReadOnly, EditDefaultsOnly, Category = "Animations" )
	TObjectPtr<USYAbilityAnimationDataAsset> AbilityAnimationsData;
};
