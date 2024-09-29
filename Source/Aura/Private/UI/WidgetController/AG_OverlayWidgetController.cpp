// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "UI/WidgetController/AG_OverlayWidgetController.h"
#include "AbilitySystem/AG_AbilitySystemComponent.h"
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

    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetHealthAttribute()).AddLambda([=, this](const FOnAttributeChangeData& Data) { OnHealthChanged.Broadcast(Data.NewValue); });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxHealthAttribute()).AddLambda([=, this](const FOnAttributeChangeData& Data) { OnMaxHealthChanged.Broadcast(Data.NewValue); });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetManaAttribute()).AddLambda([=, this](const FOnAttributeChangeData& Data) { OnManaChanged.Broadcast(Data.NewValue); });
    AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AuraAttributeSet->GetMaxManaAttribute()).AddLambda([=, this](const FOnAttributeChangeData& Data) { OnMaxManaChanged.Broadcast(Data.NewValue); });

    if (auto* ASC = Cast<UAG_AbilitySystemComponent>(AbilitySystemComponent))
    {
        // when receive asset tags
        ASC->OnEffectAssetTags().AddLambda(
            [=, this](const FGameplayTagContainer& AssetTags)
            {
                for (const auto& Tag : AssetTags)
                {
                    const FGameplayTag MessageTag = FGameplayTag::RequestGameplayTag(FName("Message"));
                    if (Tag.MatchesTag(MessageTag))
                    {
                        const FUIWidgetRow* Row = GetDataTableRowByTag<FUIWidgetRow>(MessageWidgetDataTable, Tag);
                        OnMessageWidgetRow.Broadcast(*Row);
                    }
                }
            });
    }
}
