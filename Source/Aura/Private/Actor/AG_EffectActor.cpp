// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Actor/AG_EffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AAG_EffectActor::AAG_EffectActor()
{
    PrimaryActorTick.bCanEverTick = false;

    SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}

void AAG_EffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
    auto* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
    if (!TargetASC || !GameplayEffectClass) return;

    FGameplayEffectContextHandle EffectContextHandle = TargetASC->MakeEffectContext();
    EffectContextHandle.AddSourceObject(this);
    const FGameplayEffectSpecHandle EffectSpecHandle = TargetASC->MakeOutgoingSpec(GameplayEffectClass, 1.0f, EffectContextHandle);
    const FActiveGameplayEffectHandle ActiveEffectHandle = TargetASC->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data);

    const bool bIsInfinite = EffectSpecHandle.Data->Def->DurationPolicy == EGameplayEffectDurationType::Infinite;
    if (bIsInfinite && InfiniteEffectRemovalPolicy != EEffectRemovalPolicy::DoNotRemove)
    {
        ActiveEffectsHandles.Add(ActiveEffectHandle, TargetASC);
    }
}

void AAG_EffectActor::OnOverlap(AActor* TargetActor)
{
    if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
    {
        ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
    }
    if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
    {
        ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
    }
    if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
    {
        ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
    }
}

void AAG_EffectActor::OnEndOverlap(AActor* TargetActor)
{
    if (InstantEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
    {
        ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
    }
    if (DurationEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
    {
        ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
    }
    if (InfiniteEffectApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
    {
        ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
    }
    if (InfiniteEffectRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
    {
        auto* TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
        if (!IsValid(TargetASC)) return;

        TArray<FActiveGameplayEffectHandle> HandlesToRemove;
        for (auto& HandlePair : ActiveEffectsHandles)
        {
            if (TargetASC == HandlePair.Value)
            {
                TargetASC->RemoveActiveGameplayEffect(HandlePair.Key, 1);
                HandlesToRemove.Add(HandlePair.Key);
            }
        }
        for (auto& Handle : HandlesToRemove)
        {
            ActiveEffectsHandles.FindAndRemoveChecked(Handle);
        }
        HandlesToRemove.Empty();
    }
}
