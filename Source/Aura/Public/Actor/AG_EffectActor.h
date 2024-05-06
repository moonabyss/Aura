// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AG_EffectActor.generated.h"

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
    UFUNCTION(BlueprintCallable)
    virtual void ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass);

    UFUNCTION(BlueprintCallable)
    void OnOverlap(AActor* TargetActor);

    UFUNCTION(BlueprintCallable)
    void OnEndOverlap(AActor* TargetActor);

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    bool bDestroyOnEffectRemoval{false};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectApplicationPolicy InstantEffectApplicationPolicy{EEffectApplicationPolicy::DoNotApply};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectApplicationPolicy DurationEffectApplicationPolicy{EEffectApplicationPolicy::DoNotApply};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectApplicationPolicy InfiniteEffectApplicationPolicy{EEffectApplicationPolicy::DoNotApply};

    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Applied Effects")
    EEffectRemovalPolicy InfiniteEffectRemovalPolicy{EEffectRemovalPolicy::RemoveOnEndOverlap};

private:
};
