﻿#pragma once
#include "GameplayTagContainer.h"

/**
 * The singleton container for Gameplay Tags used in SaovYmladda.
 * Provides easy access to the Gameplay Tags used in Code.
 */
struct FSYGameplayTags
{
public:
	//** Singleton Getter */
	static const FSYGameplayTags& Get() { return GameplayTags; }

	/** Initializes native gameplay tags */
	static void InitializeNativeGameplayTags();

	/**	---Ability Tags--- **/

	FGameplayTag Abilities_Action_Jump;
	FGameplayTag Abilities_Action_Dodge;

	FGameplayTag Abilities_Attack_Light;


	/** ---State Tags--- **/
	FGameplayTag State_Character_InAction_Jumping;
	FGameplayTag State_Character_InAction_Dodging;
	FGameplayTag State_Character_InAction_Attacking;

	FGameplayTag State_Resources_StaminaBlocked;

private:
	static FSYGameplayTags GameplayTags;
};
