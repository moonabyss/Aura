// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_CharacterBase.h"
#include "AbilitySystemComponent.h"

AAG_CharacterBase::AAG_CharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
    check(Weapon);
    Weapon->SetupAttachment(GetMesh(), "WeaponHandSocket");
    Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAG_CharacterBase::InitializePrimaryAttributes() const
{
    if (!DefaultPrimaryAttributes || !GetAbilitySystemComponent()) return;

    const FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
    const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultPrimaryAttributes, 1.0f, ContextHandle);
    GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}
