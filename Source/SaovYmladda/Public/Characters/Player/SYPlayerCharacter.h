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
 * 
 * It's designed to be a base for Player Character Blueprint.
 * It Implements the IPlayerInputReceiverInterface to work with the Player Controller.
 */
UCLASS( Blueprintable, Abstract )
class SAOVYMLADDA_API ASYPlayerCharacter : public ASYCharacterBase, public IPlayerInputReceiverInterface
{
	GENERATED_BODY()

public:
	/**
	 * Default Constructor.
	 * Sets up Spring Arm, Camera Components and Movement properties.
	 */
	ASYPlayerCharacter();

	//~ Begin APawn Interface

	/** Calls initialization functions for GAS */
	virtual void PossessedBy( AController* NewController ) override;

	//~ End APawn Interface


	//~ Begin IPlayerInputReceiverInterface
	
	/** Handles dodge input, tries to activate a Dodge Ability */
	virtual void RequestDodge_Implementation() override;

	/** Handles jump input, tries to activate a Jump Ability */
	virtual void RequestJump_Implementation() override;

	/** Handles camera look input and applies it to the controller. */
	virtual void RequestLook_Implementation( const FInputActionValue& Value ) override;

	/** Handles character movement input and applies movement relative to camera rotation. */
	virtual void RequestMove_Implementation( const FInputActionValue& Value ) override;

	//~ End IPlayerInputReceiverInterface

protected:
	//~ Begin ASYCharacterBase Interface

	/** Adds reference to PlayerState's ASC and AS */
	virtual void InitializeAbilityActorInfo() override;

	/** Applies Effects that initialize default Attributes */
	virtual void InitializeDefaultAttributes() const override;

	//~ End ASYCharacterBase Interface

private:
	//~ Begin ACharacter Interface

	/** Disables orientation to movement when the character is in the air */
	UFUNCTION()
	virtual void OnMovementModeChanged( EMovementMode PrevMovementMode, uint8 PreviousCustomMode ) override;

	//~ Begin ACharacter Interface


	/** The camera boom positioning the camera behind the character */
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true") )
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	/** The camera that follows the character */
	UPROPERTY( BlueprintReadOnly, VisibleAnywhere, Category = "Camera", meta = (AllowPrivateAccess = "true") )
	TObjectPtr<UCameraComponent> CameraComponent;
};
