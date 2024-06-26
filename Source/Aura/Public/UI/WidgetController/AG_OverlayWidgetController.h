// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "AG_Types.h"
#include "UI/WidgetController/AG_WidgetController.h"

#include "AG_OverlayWidgetController.generated.h"

UCLASS(BlueprintType, Blueprintable)
class AURA_API UAG_OverlayWidgetController : public UAG_WidgetController
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnAttributeChangedSignature OnHealthChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnAttributeChangedSignature OnMaxHealthChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnAttributeChangedSignature OnManaChanged;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
    FOnAttributeChangedSignature OnMaxManaChanged;

    virtual void BroadcastInitialValues() const override;
    virtual void BindCallbacksToDependencies() override;

    UPROPERTY(BlueprintAssignable, Category = "GAS|Messages")
    FOnMessageWidgetRowSignature OnMessageWidgetRow;

protected:
    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Widget Data")
    TObjectPtr<UDataTable> MessageWidgetDataTable{nullptr};

private:
    template <typename T>
    T* GetDataTableRowByTag(UDataTable* DataTable, const FGameplayTag& Tag)
    {
        return DataTable ? DataTable->FindRow<T>(Tag.GetTagName(), TEXT("")) : nullptr;
    }
};
