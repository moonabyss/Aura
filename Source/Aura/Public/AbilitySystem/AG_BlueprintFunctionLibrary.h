// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "AG_BlueprintFunctionLibrary.generated.h"

class UAG_OverlayWidgetController;

UCLASS()
class AURA_API UAG_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintPure, Category = "UI|Widget Controller")
    static UAG_OverlayWidgetController* GetOverlayWidgetGontroller(const UObject* WorldContextObject);
};
