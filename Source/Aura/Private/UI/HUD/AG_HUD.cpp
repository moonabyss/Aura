// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/HUD/AG_HUD.h"
#include "UI/Widget/AG_UserWidget.h"

void AAG_HUD::BeginPlay()
{
    Super::BeginPlay();

    if (!OverlayWidgetClass) return;
    UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
    check(Widget);
    Widget->AddToViewport();
}
