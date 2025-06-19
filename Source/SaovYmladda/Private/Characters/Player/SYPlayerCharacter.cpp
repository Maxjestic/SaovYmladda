// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Characters/Player/SYPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "InputActionValue.h"
#include "AbilitySystem/SYAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "Core/FSYGameplayTags.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/SYPlayerState.h"

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

void ASYPlayerCharacter::PossessedBy( AController* NewController )
{
	Super::PossessedBy( NewController );

	InitializeAbilityActorInfo();
	InitializeDefaultAttributes();
	AddDefaultAbilities();
}

void ASYPlayerCharacter::RequestAttack_Implementation()
{	
	if (USYAbilitySystemComponent* ASC = Cast<USYAbilitySystemComponent>(AbilitySystemComponent))
	{
		ASC->TryActivateAbilityByGameplayTag( FSYGameplayTags::Get().Abilities_Attack_Light );
	}
}

void ASYPlayerCharacter::RequestDodge_Implementation()
{
	// TODO: Limit to combat
	if (USYAbilitySystemComponent* ASC = Cast<USYAbilitySystemComponent>(AbilitySystemComponent))
	{
		ASC->TryActivateAbilityByGameplayTag( FSYGameplayTags::Get().Abilities_Action_Dodge );
	}
}

void ASYPlayerCharacter::RequestJump_Implementation()
{
	// TODO: Roll if in combat

	// Jump if not in combat
	if (USYAbilitySystemComponent* ASC = Cast<USYAbilitySystemComponent>(AbilitySystemComponent))
	{
		ASC->TryActivateAbilityByGameplayTag( FSYGameplayTags::Get().Abilities_Action_Jump );
	}
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

void ASYPlayerCharacter::InitializeAbilityActorInfo()
{
	ASYPlayerState* SYPlayerState = GetPlayerState<ASYPlayerState>();
	ensure( SYPlayerState );
	SYPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo( SYPlayerState, this );

	AbilitySystemComponent = SYPlayerState->GetAbilitySystemComponent();
	AttributeSet = SYPlayerState->GetAttributeSet();
}

void ASYPlayerCharacter::InitializeDefaultAttributes() const
{
	ApplyEffectToSelf( PrimaryAttributesEffect );
	ApplyEffectToSelf( VitalAttributesEffect );
	ApplyEffectToSelf( StaminaRegenEffect );
}

void ASYPlayerCharacter::OnMovementModeChanged( EMovementMode PrevMovementMode, uint8 PreviousCustomMode )
{
	Super::OnMovementModeChanged( PrevMovementMode, PreviousCustomMode );

	if ( UCharacterMovementComponent* MovementComp = GetCharacterMovement() )
	{
		MovementComp->bOrientRotationToMovement = !MovementComp->IsFalling();
	}
}
