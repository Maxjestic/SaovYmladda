// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "SYAbilitySystemComponent.generated.h"

/**
 * The project-specific Ability System Component for SaovYmladda.
 *
 * Defines Gameplay Ability System logic for the project.
 */
UCLASS()
class SAOVYMLADDA_API USYAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()

public:
	/**
	 * Grants default abilities to the owner of ASC.
	 * @param DefaultAbilities - abilities that will be granted
	 */
	void AddDefaultAbilities( const TArray<TSubclassOf<UGameplayAbility>>& DefaultAbilities );
};
