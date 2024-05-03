// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"

#include "AG_HUD.generated.h"

class UAG_UserWidget;
UCLASS()
class AURA_API AAG_HUD : public AHUD
{
    GENERATED_BODY()

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere)
    TSubclassOf<UAG_UserWidget> OverlayWidgetClass;
};
