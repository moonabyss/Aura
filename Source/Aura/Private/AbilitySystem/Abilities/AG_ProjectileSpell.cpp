// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/Abilities/AG_ProjectileSpell.h"
#include "Actor/AG_Projectile.h"
#include "Interaction/CombatInterface.h"

void UAG_ProjectileSpell::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
    Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);
}

void UAG_ProjectileSpell::SpawnProjectile()
{
    const bool bIsServer = GetAvatarActorFromActorInfo()->HasAuthority();
    if (!bIsServer) return;

    if (const auto* CombatInterface = Cast<ICombatInterface>(GetAvatarActorFromActorInfo()))
    {
        const FVector SocketLocation = CombatInterface->GetCombatSocketLocation();
        FTransform SpawnTransform;
        SpawnTransform.SetLocation(SocketLocation);
        // TODO: Set the Projectile Rotation

        checkf(ProjectileClass, TEXT("ProjectileClass is not set in %s"), *GetNameSafe(this));
        auto* Projectile = GetWorld()->SpawnActorDeferred<AAG_Projectile>(ProjectileClass, SpawnTransform, GetOwningActorFromActorInfo(), Cast<APawn>(GetOwningActorFromActorInfo()), ESpawnActorCollisionHandlingMethod::AlwaysSpawn);

        // TODO: Give the projectile a Gameplay Effect Spec for causing Damage

        Projectile->FinishSpawning(SpawnTransform);
    }
}
