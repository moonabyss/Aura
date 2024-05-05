// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/HUD/AG_HUD.h"
#include "UI/Widget/AG_UserWidget.h"
#include "UI/WidgetController/AG_OverlayWidgetController.h"

UAG_OverlayWidgetController* AAG_HUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
    if (!OverlayWidgetController)
    {
        OverlayWidgetController = NewObject<UAG_OverlayWidgetController>(this, OverlayWidgetControllerClass);
        OverlayWidgetController->SetWidgetControllerParams(WCParams);
    }

    return OverlayWidgetController;
}

void AAG_HUD::InitOverlay(const FWidgetControllerParams& Params)
{
    check(OverlayWidgetClass);
    check(OverlayWidgetControllerClass);

    UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
    check(Widget);
    OverlayWidget = Cast<UAG_UserWidget>(Widget);
    auto* WidgetController = GetOverlayWidgetController(Params);
    if (!WidgetController) return;

    OverlayWidget->SetWidgetController(WidgetController);
    WidgetController->BroadcastInitialValues();
    Widget->AddToViewport();
}
