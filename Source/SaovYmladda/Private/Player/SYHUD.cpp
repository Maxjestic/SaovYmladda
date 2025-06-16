// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Player/SYHUD.h"

#include "Player/SYPlayerState.h"
#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "UI/Widgets/SYUserWidget.h"

void ASYHUD::BeginPlay()
{
	Super::BeginPlay();

	InitOverlay();
}

UOverlayWidgetController* ASYHUD::GetOverlayWidgetController( const FWidgetControllerParams& WidgetControllerParams )
{
	if ( OverlayWidgetController == nullptr )
	{
		OverlayWidgetController = NewObject<UOverlayWidgetController>( this, OverlayWidgetControllerClass );
		OverlayWidgetController->SetWidgetControllerParams( WidgetControllerParams );
		OverlayWidgetController->BindCallbacksToDelegates();
	}
	return OverlayWidgetController;
}

void ASYHUD::InitOverlay()
{
	ensureMsgf( OverlayWidgetClass, TEXT("OverlayWidgetClass not set in ASYHUD blueprint.") );
	ensureMsgf( OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass not set in ASYHUD blueprint.") );

	const APlayerController* PlayerController = GetOwningPlayerController();
	if ( PlayerController == nullptr )
	{
		return;
	}

	const ASYPlayerState* PlayerState = PlayerController->GetPlayerState<ASYPlayerState>();
	if ( PlayerState == nullptr )
	{
		return;
	}

	UAbilitySystemComponent* ASC = PlayerState->GetAbilitySystemComponent();
	UAttributeSet* AS = PlayerState->GetAttributeSet();
	if ( ASC == nullptr || AS == nullptr )
	{
		return;
	}

	const FWidgetControllerParams WidgetControllerParams = FWidgetControllerParams( ASC, AS );

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController( WidgetControllerParams );

	UUserWidget* Widget = CreateWidget<UUserWidget>( GetWorld(), OverlayWidgetClass );
	OverlayWidget = Cast<USYUserWidget>( Widget );
	OverlayWidget->SetWidgetController( WidgetController );
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}
