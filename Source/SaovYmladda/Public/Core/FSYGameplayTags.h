#pragma once
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


	/** ---State Tags--- **/
	FGameplayTag State_Character_InAction_Jumping;

private:
	static FSYGameplayTags GameplayTags;
};
