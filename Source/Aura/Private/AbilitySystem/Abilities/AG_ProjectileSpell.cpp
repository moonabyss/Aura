// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/Abilities/AG_ProjectileSpell.h"
#include "Kismet/KismetSystemLibrary.h"

void UAG_ProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo,
                                          const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

    UKismetSystemLibrary::PrintString(this, FString("ActivateAbility (C++)"), true, true, FColor::Yellow, 3.0f);
}
