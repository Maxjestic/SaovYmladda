// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Characters/Player/SYPlayerCharacter.h"

#include "InputActionValue.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASYPlayerCharacter::ASYPlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>( TEXT( "SpringArmComponent" ) );
	SpringArmComponent->SetupAttachment( RootComponent );
	SpringArmComponent->TargetArmLength = 700.f;
	SpringArmComponent->bUsePawnControlRotation = true;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>( TEXT( "CameraComponent" ) );
	CameraComponent->SetupAttachment( SpringArmComponent, USpringArmComponent::SocketName );
	CameraComponent->bUsePawnControlRotation = false;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator( 0.0f, 500.0f, 0.0f );
}

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
	Jump();
	// Roll if in combat
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
