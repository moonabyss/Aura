// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/AG_AbilitySystemComponent.h"

#include "AbilitySystem/Abilities/AG_GameplayAbility.h"

void UAG_AbilitySystemComponent::AbilityActorInfoSet()
{
    OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::EffectApplied);
}

void UAG_AbilitySystemComponent::AddCharacterAbilities(const TArray<TSubclassOf<UGameplayAbility>>& AbilitiesToAdd)
{
    for (const auto& AbilityClass : AbilitiesToAdd)
    {
        auto AbilitySpec = FGameplayAbilitySpec(AbilityClass, 1);
        if (const auto* AuraAbility = Cast<UAG_GameplayAbility>(AbilitySpec.Ability))
        {
            AbilitySpec.DynamicAbilityTags.AddTag(AuraAbility->StartupInputTag);
            GiveAbility(AbilitySpec);
        }
    }
}

void UAG_AbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
    if (!InputTag.IsValid()) return;

    for (auto& AbilitySpec : GetActivatableAbilities())
    {
        if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
        {
            AbilitySpecInputReleased(AbilitySpec);
        }
    }
}

void UAG_AbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
    if (!InputTag.IsValid()) return;

    for (auto& AbilitySpec : GetActivatableAbilities())
    {
        if (AbilitySpec.DynamicAbilityTags.HasTagExact(InputTag))
        {
            AbilitySpecInputPressed(AbilitySpec);
            if (!AbilitySpec.IsActive())
            {
                TryActivateAbility(AbilitySpec.Handle);
            }
        }
    }
}

void UAG_AbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
    FGameplayTagContainer TagContainer;
    EffectSpec.GetAllAssetTags(TagContainer);
    // broadcast all tags from applied effect
    EffectAssetTags.Broadcast(TagContainer);
}
