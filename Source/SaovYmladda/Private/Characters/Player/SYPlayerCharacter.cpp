// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Characters/Player/SYPlayerCharacter.h"

#include "InputActionValue.h"

void ASYPlayerCharacter::RequestDodge_Implementation()
{
	// Dodging is possible only in combat
	if ( GEngine )
	{
		GEngine->AddOnScreenDebugMessage( 1, 3, FColor::Red, "RequestDodge Done" );
	}
}

void ASYPlayerCharacter::RequestJump_Implementation()
{
	// Jump if not in combat
	// Roll if in combat
	Jump();
}

void ASYPlayerCharacter::RequestLook_Implementation( const FInputActionValue& Value )
{
	const FVector2D LookVector = Value.Get<FVector2D>();

	AddControllerYawInput( LookVector.X );
	AddControllerPitchInput( LookVector.Y );
}

void ASYPlayerCharacter::RequestMove_Implementation( const FInputActionValue& Value )
{
	const FVector2D MovementVector = Value.Get<FVector2D>();

	const FRotator YawRotation( 0.f, GetControlRotation().Yaw, 0.f );

	const FVector ForwardDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::X );
	const FVector RightDirection = FRotationMatrix( YawRotation ).GetUnitAxis( EAxis::Y );

	AddMovementInput( ForwardDirection, MovementVector.Y );
	AddMovementInput( RightDirection, MovementVector.X );
}
