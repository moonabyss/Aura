// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/Widget/AG_UserWidget.h"

void UAG_UserWidget::SetWidgetController(UObject* InWidgetController)
{
    WidgetController = InWidgetController;
    WidgetControllerSet();
}
