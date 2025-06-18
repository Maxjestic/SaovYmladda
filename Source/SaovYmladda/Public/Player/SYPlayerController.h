// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SYPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

/**
 * The project-specific Player Controller for SaovYmladda.
 *
 * This class serves as the base for Player Controller.
 * It adds Input Mapping Context and binds Input Actions to handlers which request reaction for input.
 */
UCLASS( Blueprintable, Abstract )
class SAOVYMLADDA_API ASYPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

protected:
	//~ Begin APlayerController Interface
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	//~ End APlayerController Interface


	/// --- Input Handles ---

	/** Called for dodge input */
	void HandleAttack();

	/** Called for dodge input */
	void HandleDodge();

	/** Called for jump input */
	void HandleJump();

	/** Called for look input */
	void HandleLook( const FInputActionValue& InputActionValue );

	/** Called for move input */
	void HandleMove( const FInputActionValue& InputActionValue );


	/// -- Input Assets ---

	/** Input Mapping Context to be used for player input. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input" )
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	/** Input Action for attack. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input|Actions" )
	TObjectPtr<UInputAction> AttackAction;

	/** Input Action for dodging. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input|Actions" )
	TObjectPtr<UInputAction> DodgeAction;

	/** Input Action for jumping. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input|Actions" )
	TObjectPtr<UInputAction> JumpAction;

	/** Input Action for looking around */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input|Actions" )
	TObjectPtr<UInputAction> LookAction;

	/** Input Action for moving the character */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input|Actions" )
	TObjectPtr<UInputAction> MoveAction;
};
