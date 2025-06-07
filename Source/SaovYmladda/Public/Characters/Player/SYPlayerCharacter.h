// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SYCharacterBase.h"
#include "Interfaces/PlayerInputReceiverInterface.h"
#include "SYPlayerCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;

/**
 * The base class for the Player Character in SaovYmladda.
 * It's designed to be a base for Player Character Blueprint.
 * Implements the IPlayerInputReceiverInterface to work with the Player Controller.
 */
UCLASS( Abstract, Blueprintable )
class SAOVYMLADDA_API ASYPlayerCharacter : public ASYCharacterBase, public IPlayerInputReceiverInterface
{
	GENERATED_BODY()

public:
	/**
	 * Default Constructor.
	 * Sets up Spring Arm, Camera Components and Movement properties.
	 */
	ASYPlayerCharacter();

	//~ Begin IPlayerInputReceiverInterface
	/** TODO: Trigger Dodge Gameplay Ability */
	virtual void RequestDodge_Implementation() override;

	/**
	 * Calls the base ACharacter::Jump() function to start the jump action.
	 * TODO: Change to Trigger Jump Gameplay Ability
	 */
	virtual void RequestJump_Implementation() override;

	/** Handles camera look input and applies it to the controller. */
	virtual void RequestLook_Implementation( const FInputActionValue& Value ) override;

	/** Handles character movement input and applies movement relative to camera rotation. */
	virtual void RequestMove_Implementation( const FInputActionValue& Value ) override;
	//~ End IPlayerInputReceiverInterface

private:
	/** The camera boom positioning the camera behind the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true") )
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	/** The camera that follows the character */
	UPROPERTY( VisibleAnywhere, BlueprintReadOnly, Category = "Camera", meta = (AllowPrivateAccess = "true") )
	TObjectPtr<UCameraComponent> CameraComponent;
};
