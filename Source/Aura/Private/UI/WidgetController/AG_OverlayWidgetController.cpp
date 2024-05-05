// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/WidgetController/AG_OverlayWidgetController.h"
#include "AbilitySystem/AG_AttributeSet.h"

void UAG_OverlayWidgetController::BroadcastInitialValues() const
{
    Super::BroadcastInitialValues();

    const auto* AuraAttributeSet = Cast<UAG_AttributeSet>(AttributeSet);
    if (!AuraAttributeSet) return;

    OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
    OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
    OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
    OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
}
