// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SYPlayerController.generated.h"

struct FInputActionValue;
class UInputAction;
class UInputMappingContext;
/**
 * 
 */
UCLASS( Abstract, Blueprintable )
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
	/// These functions will be bound to Input Actions

	/** Called for dodge input */
	void HandleDodge();

	/** Called for jump input */
	void HandleJump();

	/** Called for look input */
	void HandleLook( const FInputActionValue& InputActionValue );

	/** Called for move input */
	void HandleMove( const FInputActionValue& InputActionValue );


	/// -- Input Assets ---
	/// Mapping Contexts and Input Actions used by Controller

	/** Input Mapping Context to be used for player input. */
	UPROPERTY( EditDefaultsOnly, BlueprintReadOnly, Category = "Enhanced Input" )
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

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
