// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "ActiveGameplayEffectHandle.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AG_EffectActor.generated.h"

class UAbilitySystemComponent;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
    ApplyOnOverlap = 0,
    ApplyOnEndOverlap,
    DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
    RemoveOnEndOverlap = 0,
    DoNotRemove
};

UCLASS()
class AURA_API AAG_EffectActor : public AActor
{
    GENERATED_BODY()

public:
    AAG_EffectActor();

protected:
    virtual void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

    UFUNCTION(BlueprintCallable)
    void OnOverlap(AActor* TargetActor);

    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* TargetActor);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    bool bDestroyOnEffectRemoval{false};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Instant Effect")
    TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Instant Effect")
    EEffectApplicationPolicy InstantEffectApplicationPolicy{EEffectApplicationPolicy::DoNotApply};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Duration Effect")
    TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Duration Effect")
    EEffectApplicationPolicy DurationEffectApplicationPolicy{EEffectApplicationPolicy::DoNotApply};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Infinite Effect")
    TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Infinite Effect")
    EEffectApplicationPolicy InfiniteEffectApplicationPolicy{EEffectApplicationPolicy::DoNotApply};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects|Infinite Effect")
    EEffectRemovalPolicy InfiniteEffectRemovalPolicy{EEffectRemovalPolicy::RemoveOnEndOverlap};

private:
    TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectsHandles;
};
