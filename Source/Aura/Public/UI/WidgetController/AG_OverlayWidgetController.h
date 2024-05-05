// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "AG_Types.h"
#include "UI/WidgetController/AG_WidgetController.h"

#include "AG_OverlayWidgetController.generated.h"

UCLASS(BlueprintType)
class AURA_API UAG_OverlayWidgetController : public UAG_WidgetController
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnHealthChangedSignature OnHealthChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnMaxHealthChangedSignature OnMaxHealthChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnManaChangedSignature OnManaChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnMaxManaChangedSignature OnMaxManaChanged;

    virtual void BroadcastInitialValues() const override;
    virtual void BindCallbacksToDependencies() override;

private:
    void HealthChanged(const FOnAttributeChangeData& Data) const;
    void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
    void ManaChanged(const FOnAttributeChangeData& Data) const;
    void MaxManaChanged(const FOnAttributeChangeData& Data) const;
};
