// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "CoreMinimal.h"

#include "AG_UserWidget.generated.h"

UCLASS()
class AURA_API UAG_UserWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void SetWidgetController(UObject* InWidgetController);

protected:
    UPROPERTY(BlueprintReadOnly)
    TObjectPtr<UObject> WidgetController;

    UFUNCTION(BlueprintImplementableEvent)
    void WidgetControllerSet();
};
