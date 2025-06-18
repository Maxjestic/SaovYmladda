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
	
	GameplayTags.Abilities_Action_Dodge = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "Abilities.Action.Dodge" ),
		FString( "Dodge Ability Tag" ) );
	
	
	GameplayTags.Abilities_Attack_Light = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "Abilities.Attack.Light" ),
		FString( "Light Attack Ability Tag" ) );


	/** ---State Tags--- **/

	GameplayTags.State_Character_InAction_Jumping = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "State.Character.InAction.Jumping" ),
		FString( "Tag added when the character is jumping" ) );

	GameplayTags.State_Character_InAction_Dodging = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "State.Character.InAction.Dodging" ),
		FString( "Tag added when the character is dodging" ) );

	GameplayTags.State_Character_InAction_Attacking = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "State.Character.InAction.Attacking" ),
		FString( "Tag added when the character is attacking" ) );

	
	GameplayTags.State_Resources_StaminaBlocked = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName( "State.Resources.StaminaBlocked" ),
		FString( "Tag preventing regeneration of Stamina" ) );
}
