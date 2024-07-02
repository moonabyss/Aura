// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AbilitySystem/Abilities/AG_GameplayAbility.h"
#include "CoreMinimal.h"

#include "AG_ProjectileSpell.generated.h"

UCLASS()
class AURA_API UAG_ProjectileSpell : public UAG_GameplayAbility
{
    GENERATED_BODY()

protected:
    virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                 const FGameplayEventData* TriggerEventData) override;
};
