// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "SYPlayerState.generated.h"

class UAttributeSet;

/**
 * The project-specific Player State for SaovYmladda.
 *
 * This class serves as the base for Player State and is suited to work with Gameplay Ability System.
 * It holds Attribute Set and Ability System Component for the Player.
 * It implements IAbilitySystemInterface.
 */
UCLASS( Blueprintable, Abstract )
class SAOVYMLADDA_API ASYPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	/**
	 * Default Constructor.
	 * Sets up AbilitySystemComponent and AttributeSet.
	 */
	ASYPlayerState();

	//~ Begin IAbilitySystemInterface

	/**
	 * AbilitySystemComponent Getter.
	 * @return A pointer to this character's AbilitySystemComponent.
	 */
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	//~ End IAbilitySystemInterface

	/** AttributeSet getter */
	FORCEINLINE UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	/**
	 * The Player character's Ability System Component. 
	 * Responsible for handling abilities and gameplay effects.
	 * Player Character references this.
	 */
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Abilities" )
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	/**
	 * The Player character's Attribute Set.
	 * Contains attributes like Health, Stamina, etc.
	 * Player Character references this.
	 */
	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;
};
