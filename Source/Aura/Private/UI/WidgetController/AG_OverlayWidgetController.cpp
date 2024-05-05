// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/WidgetController/AG_OverlayWidgetController.h"
#include "AbilitySystem/AG_AttributeSet.h"

void UAG_OverlayWidgetController::BroadcastInitialValues() const
{
    const auto* AuraAttributeSet = Cast<UAG_AttributeSet>(AttributeSet);
    if (!AuraAttributeSet) return;

    OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
    OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
    OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
    OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
}
void UAG_OverlayWidgetController::BindCallbacksToDependencies()
{
    const auto* AuraAttributeSet = Cast<UAG_AttributeSet>(AttributeSet);
    if (!AuraAttributeSet || !AbilitySystemComponent) return;

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::HealthChanged);
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::MaxHealthChanged);
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddUObject(this, &ThisClass::ManaChanged);
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &ThisClass::MaxManaChanged);
}

void UAG_OverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
    OnHealthChanged.Broadcast(Data.NewValue);
}

void UAG_OverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
    OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UAG_OverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
    OnManaChanged.Broadcast(Data.NewValue);
}

void UAG_OverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
    OnMaxManaChanged.Broadcast(Data.NewValue);
}
