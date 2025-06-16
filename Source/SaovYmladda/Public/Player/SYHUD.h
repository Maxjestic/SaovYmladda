// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "SYHUD.generated.h"

struct FWidgetControllerParams;
class UOverlayWidgetController;
class USYUserWidget;
class UAttributeSet;
class UAbilitySystemComponent;

/**
 * The project-specific HUD for SaovYmladda.
 *
 * This class serves as the base for HUD.
 */
UCLASS( Blueprintable, Abstract )
class SAOVYMLADDA_API ASYHUD : public AHUD
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;

	/**
	 * Creates Overlay Widget Controller if it doesn't exist.
	 * @param WidgetControllerParams - References to Models used by the Controller
	 * @return - Overlay Widget Controller.
	 */
	UOverlayWidgetController* GetOverlayWidgetController( const FWidgetControllerParams& WidgetControllerParams );

	/** Creates Overlay Widget with proper Controller */
	void InitOverlay();

private:
	/** View - Class used to spawn Overlay Widget */
	UPROPERTY( EditAnywhere )
	TSubclassOf<USYUserWidget> OverlayWidgetClass;

	/** Controller - Class used to spawn Overlay Widget Controller */
	UPROPERTY( EditAnywhere )
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;

	/** View - Stored Overlay Widget */
	UPROPERTY()
	TObjectPtr<USYUserWidget> OverlayWidget;

	/** Controller - Stored Overlay Widget Controller */
	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
};
