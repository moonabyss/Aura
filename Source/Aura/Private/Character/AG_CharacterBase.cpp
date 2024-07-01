// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_CharacterBase.h"
#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystemComponent.h"

AAG_CharacterBase::AAG_CharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
    check(Weapon);
    Weapon->SetupAttachment(GetMesh(), "WeaponHandSocket");
    Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAG_CharacterBase::ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level /*= 1.0f*/) const
{
    if (!GameplayEffectClass || !GetAbilitySystemComponent()) return;

    FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
    ContextHandle.AddSourceObject(this);
    const FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(GameplayEffectClass, Level, ContextHandle);
    GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
}

void AAG_CharacterBase::InitializeDefaultAttributes() const
{
    ApplyEffectToSelf(DefaultPrimaryAttributes);
    ApplyEffectToSelf(DefaultSecondaryAttributes);
    ApplyEffectToSelf(DefaultVitalAttributes);
}

void AAG_CharacterBase::AddCharacterAbilities()
{
    if (!HasAuthority()) return;
    auto* AuraASC = CastChecked<UAG_AbilitySystemComponent>(AbilitySystemComponent);

    AuraASC->AddCharacterAbilities(StartupAbilities);
}
