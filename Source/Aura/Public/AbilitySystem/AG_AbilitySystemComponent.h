// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AbilitySystemComponent.h"
#include "CoreMinimal.h"

#include "AG_AbilitySystemComponent.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FOnEffectAssetTagsSignature, const FGameplayTagContainer& /*AssetTags*/);

UCLASS()
class AURA_API UAG_AbilitySystemComponent : public UAbilitySystemComponent
{
    GENERATED_BODY()

public:
    /** call after ActorInfo was set */
    void AbilityActorInfoSet();

    FOnEffectAssetTagsSignature& OnEffectAssetTags() { return EffectAssetTags; }

protected:
    /** callback */
    void EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);

private:
    FOnEffectAssetTagsSignature EffectAssetTags;
};
