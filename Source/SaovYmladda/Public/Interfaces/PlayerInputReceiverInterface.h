// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "PlayerInputReceiverInterface.generated.h"

struct FInputActionValue;

UINTERFACE( MinimalAPI )
class UPlayerInputReceiverInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * The Interface that defines possible reactions to input.
 *
 * Decouples Player Controller and controlled Pawn.
 */
class SAOVYMLADDA_API IPlayerInputReceiverInterface
{
	GENERATED_BODY()

public:
	/** Handles the attack input action. Called from the Player Controller. */
	UFUNCTION( BlueprintNativeEvent, Category = "Player Input" )
	void RequestAttack();
	
	/** Handles the dodge input action. Called from the Player Controller. */
	UFUNCTION( BlueprintNativeEvent, Category = "Player Input" )
	void RequestDodge();

	/** Handles the jump input action. Called from the Player Controller. */
	UFUNCTION( BlueprintNativeEvent, Category = "Player Input" )
	void RequestJump();

	/** Handles the look input action. Called from the Player Controller. */
	UFUNCTION( BlueprintNativeEvent, Category = "Player Input" )
	void RequestLook( const FInputActionValue& Value );

	/** Handles the move input action. Called from the Player Controller. */
	UFUNCTION( BlueprintNativeEvent, Category = "Player Input" )
	void RequestMove( const FInputActionValue& Value );
};
