// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "UI/Widgets/SYUserWidget.h"

void USYUserWidget::SetWidgetController( UObject* InWidgetController )
{
	WidgetController = InWidgetController;
	WidgetControllerSet();
}