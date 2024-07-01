// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AG_Types.h"
#include "CoreMinimal.h"
#include "UI/WidgetController/AG_WidgetController.h"

#include "AG_AttributeMenuWidgetController.generated.h"

class UAG_AttributeInfo;

UCLASS(BlueprintType, Blueprintable)
class AURA_API UAG_AttributeMenuWidgetController : public UAG_WidgetController
{
    GENERATED_BODY()

public:
    virtual void BroadcastInitialValues() const override;
    virtual void BindCallbacksToDependencies() override;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnAttributeInfoSignature AttributeInfoDelegate;

protected:
    UPROPERTY(EditDefaultsOnly)
    TObjectPtr<UAG_AttributeInfo> AttributeInfo;

private:
    void BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const;
};
