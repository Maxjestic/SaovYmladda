// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Player/SYHUD.h"

#include "UI/WidgetControllers/OverlayWidgetController.h"
#include "UI/Widgets/SYUserWidget.h"

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

void ASYHUD::InitOverlay( UAbilitySystemComponent* AbilitySystemComponent, UAttributeSet* AttributeSet )
{
	ensureMsgf( OverlayWidgetClass, TEXT("OverlayWidgetClass not set in ASYHUD blueprint.") );
	ensureMsgf( OverlayWidgetControllerClass, TEXT("OverlayWidgetControllerClass not set in ASYHUD blueprint.") );

	const FWidgetControllerParams WidgetControllerParams = FWidgetControllerParams(
		AbilitySystemComponent,
		AttributeSet );

	UOverlayWidgetController* WidgetController = GetOverlayWidgetController( WidgetControllerParams );

	UUserWidget* Widget = CreateWidget<UUserWidget>( GetWorld(), OverlayWidgetClass );
	OverlayWidget = Cast<USYUserWidget>( Widget );
	OverlayWidget->SetWidgetController( WidgetController );
	WidgetController->BroadcastInitialValues();
	Widget->AddToViewport();
}
