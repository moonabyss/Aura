// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AG_WidgetController.h"

#include "AG_AttributeMenuWidgetController.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AURA_API UAG_AttributeMenuWidgetController : public UAG_WidgetController
{
    GENERATED_BODY()

public:
    virtual void BroadcastInitialValues() const override;
    virtual void BindCallbacksToDependencies() override;
};
