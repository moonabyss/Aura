// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AG_EffectActor.generated.h"

class UGameplayEffect;
UCLASS()
class AURA_API AAG_EffectActor : public AActor
{
    GENERATED_BODY()

public:
    AAG_EffectActor();

protected:
    virtual void BeginPlay() override;

    UFUNCTION(BlueprintCallable)
    virtual void ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass);

    UPROPERTY(EditAnywhere, Category = "Applied Effects")
    TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;

private:
};