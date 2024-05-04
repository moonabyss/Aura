// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/WidgetController/AG_WidgetController.h"

void UAG_WidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
    PlayerController = Params.PlayerController;
    PlayerState = Params.PlayerState;
    AbilitySystemComponent = Params.AbilitySystemComponent;
    AttributeSet = Params.AttributeSet;
}
