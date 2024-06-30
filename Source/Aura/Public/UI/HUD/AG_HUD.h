// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "AG_HUD.generated.h"

class UAG_OverlayWidgetController;
class UAG_AttributeMenuWidgetController;
class UAG_UserWidget;
struct FWidgetControllerParams;

UCLASS()
class AURA_API AAG_HUD : public AHUD
{
    GENERATED_BODY()

public:
    UAG_OverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
    UAG_AttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& WCParams);
    void InitOverlay(const FWidgetControllerParams& Params);

private:
    UPROPERTY()
    UAG_UserWidget* OverlayWidget;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UAG_UserWidget> OverlayWidgetClass;

    UPROPERTY()
    TObjectPtr<UAG_OverlayWidgetController> OverlayWidgetController;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UAG_OverlayWidgetController> OverlayWidgetControllerClass;

    UPROPERTY()
    TObjectPtr<UAG_AttributeMenuWidgetController> AttributeMenuWidgetController;

    UPROPERTY(EditAnywhere)
    TSubclassOf<UAG_AttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
};
