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
 * The C++ interface that defines the behavioral contract for receiving player input.
 * Implemented by the Player Character. Called by the Player Controller.
 */
class SAOVYMLADDA_API IPlayerInputReceiverInterface
{
	GENERATED_BODY()
	
public:
	
	/** Handles the dodge input action. Called from the Player Controller. */
	UFUNCTION(BlueprintNativeEvent, Category = "Player Input")
	void RequestDodge();

	/** Handles the jump input action. Called from the Player Controller. */
	UFUNCTION(BlueprintNativeEvent, Category = "Player Input")
	void RequestJump();

	/** Handles the look input action. Called from the Player Controller. */
	UFUNCTION(BlueprintNativeEvent, Category = "Player Input")
	void RequestLook(const FInputActionValue& Value);
	
	/** Handles the move input action. Called from the Player Controller. */
	UFUNCTION(BlueprintNativeEvent, Category = "Player Input")
	void RequestMove(const FInputActionValue& Value);
};
