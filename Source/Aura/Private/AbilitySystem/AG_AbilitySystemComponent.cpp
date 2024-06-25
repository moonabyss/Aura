// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/AG_AbilitySystemComponent.h"

void UAG_AbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::EffectApplied);
}

void UAG_AbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);
    // broadcast all tags from applied effect
    EffectAssetTags.Broadcast(TagContainer);
}
