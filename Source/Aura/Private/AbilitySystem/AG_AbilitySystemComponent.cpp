// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/AG_AbilitySystemComponent.h"

void UAG_AbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::EffectApplied);
}

void UAG_AbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilitiesToAdd)
{
    for (const auto& AbilityClass : AbilitiesToAdd)
    {
        auto AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
        GiveAbilityAndActivateOnce(AbilitySpec);
    }
}

void UAG_AbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);
    // broadcast all tags from applied effect
    EffectAssetTags.Broadcast(TagContainer);
}
