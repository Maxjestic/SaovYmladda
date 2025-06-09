#include "Core/FSYGameplayTags.h"

#include "GameplayTagsManager.h"

FSYGameplayTags FSYGameplayTags::GameplayTags;

/*
Template to copy:
GameplayTags. = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "" ),
		FString( "" ) );
*/

void FSYGameplayTags::InitializeNativeGameplayTags()
{
	/**	---Ability Tags--- **/

	GameplayTags.Abilities_Action_Jump = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "Abilities.Action.Jump" ),
		FString( "Jump Ability Tag" ) );


	/** ---State Tags--- **/

	GameplayTags.State_Character_InAction_Jumping = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "State.Character.InAction.Jumping" ),
		FString( "Tag added when the character is jumping" ) );
}
