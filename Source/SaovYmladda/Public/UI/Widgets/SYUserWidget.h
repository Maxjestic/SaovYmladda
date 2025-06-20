// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SYUserWidget.generated.h"

/**
 * The project-specific Game Mode for SaovYmladda.
 *
 * This class serves as the base for the User Widgets.
 * Works with the Controller in the MVC manner.
 */
UCLASS()
class SAOVYMLADDA_API USYUserWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	/** Setter for widget controller. Informs the widget when the setting is done. */
	UFUNCTION( BlueprintCallable, Category = "Controller" )
	void SetWidgetController( UObject* InWidgetController );

	/** Controller that provides data */
	UPROPERTY( BlueprintReadOnly, Category = "Controller" );
	TObjectPtr<UObject> WidgetController;

protected:
	/** Used to set up functionality after the Widget Controller is set. */
	UFUNCTION( BlueprintImplementableEvent, Category = "Controller" )
	void WidgetControllerSet();
};
