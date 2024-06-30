// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/WidgetController/AG_AttributeMenuWidgetController.h"
#include "AbilitySystem/AG_AttributeSet.h"
#include "AbilitySystem/Data/AG_AttributeInfo.h"
#include "AuraGameplayTags.h"

void UAG_AttributeMenuWidgetController::BroadcastInitialValues() const
{
    auto* AS = CastChecked<UAG_AttributeSet>(AttributeSet);
    check(AttributeInfo);

    for (const auto& Pair : AS->TagsToAttributes)
    {
        FAuraAttributeInfo Info = AttributeInfo->FindAttributeInfoForTag(Pair.Key);
        Info.AttributeValue = Pair.Value().GetNumericValue(AS);
        AttributeInfoDelegate.Broadcast(Info);
    }
}

void UAG_AttributeMenuWidgetController::BindCallbacksToDependencies() {}
