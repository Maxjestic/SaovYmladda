// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Player/SYPlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Interfaces/PlayerInputReceiverInterface.h"

void ASYPlayerController::BeginPlay()
{
	Super::BeginPlay();

	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if ( !LocalPlayer )
	{
		UE_LOG( LogTemp, Error, TEXT("ASYPlayerController::BeginPlay - Invalid LocalPlayer.") );
		return;
	}

	UEnhancedInputLocalPlayerSubsystem* InputSystem = LocalPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>();
	if ( !InputSystem )
	{
		UE_LOG( LogTemp, Error, TEXT("ASYPlayerController::BeginPlay - Could not find the Enhanced Input Subsystem.") );
		return;
	}

	if ( !DefaultMappingContext )
	{
		UE_LOG( LogTemp,
		        Error,
		        TEXT("ASYPlayerController::BeginPlay - DefaultMappingContext is not assigned in the Blueprint!") );
		return;
	}

	InputSystem->AddMappingContext( DefaultMappingContext, 0 );
}

void ASYPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = Cast<UEnhancedInputComponent>( InputComponent );
	if ( !EnhancedInputComponent )
	{
		UE_LOG( LogTemp,
		        Error,
		        TEXT("ASYPlayerController::SetupInputComponent - Failed to cast to UEnhancedInputComponent.") );
		return;
	}

	if ( JumpAction )
	{
		EnhancedInputComponent->BindAction( JumpAction,
		                                    ETriggerEvent::Triggered,
		                                    this,
		                                    &ASYPlayerController::HandleJump );
	}
	if ( DodgeAction )
	{
		EnhancedInputComponent->BindAction( DodgeAction,
		                                    ETriggerEvent::Triggered,
		                                    this,
		                                    &ASYPlayerController::HandleDodge );
	}
	if ( LookAction )
	{
		EnhancedInputComponent->BindAction( LookAction,
		                                    ETriggerEvent::Triggered,
		                                    this,
		                                    &ASYPlayerController::HandleLook );
	}
	if ( MoveAction )
	{
		EnhancedInputComponent->BindAction( MoveAction,
		                                    ETriggerEvent::Triggered,
		                                    this,
		                                    &ASYPlayerController::HandleMove );
	}
}

void ASYPlayerController::HandleDodge()
{
	APawn* ControlledPawn = GetPawn();
	if ( ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(
		UPlayerInputReceiverInterface::StaticClass() ) )
	{
		IPlayerInputReceiverInterface::Execute_RequestDodge( ControlledPawn );
	}
}

void ASYPlayerController::HandleJump()
{
	APawn* ControlledPawn = GetPawn();
	if ( ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(
		UPlayerInputReceiverInterface::StaticClass() ) )
	{
		IPlayerInputReceiverInterface::Execute_RequestJump( ControlledPawn );
	}
}

void ASYPlayerController::HandleLook( const FInputActionValue& InputActionValue )
{
	APawn* ControlledPawn = GetPawn();
	if ( ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(
		UPlayerInputReceiverInterface::StaticClass() ) )
	{
		IPlayerInputReceiverInterface::Execute_RequestLook( ControlledPawn, InputActionValue );
	}
}

void ASYPlayerController::HandleMove( const FInputActionValue& InputActionValue )
{
	APawn* ControlledPawn = GetPawn();
	if ( ControlledPawn && ControlledPawn->GetClass()->ImplementsInterface(
		UPlayerInputReceiverInterface::StaticClass() ) )
	{
		IPlayerInputReceiverInterface::Execute_RequestMove( ControlledPawn, InputActionValue );
	}
}
