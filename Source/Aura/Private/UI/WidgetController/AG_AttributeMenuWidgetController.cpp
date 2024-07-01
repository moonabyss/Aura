// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/WidgetController/AG_AttributeMenuWidgetController.h"
#include "AbilitySystem/AG_AttributeSet.h"
#include "AbilitySystem/Data/AG_AttributeInfo.h"

void UAG_AttributeMenuWidgetController::BroadcastInitialValues() const
{
    const auto* AS = CastChecked<UAG_AttributeSet>(AttributeSet);
    check(AttributeInfo);

    for (const auto& Pair : AS->TagsToAttributes)
    {
        BroadcastAttributeInfo(Pair.Key, Pair.Value());
    }
}

void UAG_AttributeMenuWidgetController::BindCallbacksToDependencies()
{
    const auto* AS = CastChecked<UAG_AttributeSet>(AttributeSet);
    check(AttributeInfo);

    for (const auto& Pair : AS->TagsToAttributes)
    {
        AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda([this, Pair](const FOnAttributeChangeData& Data) { BroadcastAttributeInfo(Pair.Key, Pair.Value()); });
    }
}

void UAG_AttributeMenuWidgetController::BroadcastAttributeInfo(const FGameplayTag& AttributeTag, const FGameplayAttribute& Attribute) const
{
    FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(AttributeTag);
    Info.AttributeValue = Attribute.GetNumericValue(AttributeSet);
    AttributeInfoDelegate.Broadcast(Info);
}
