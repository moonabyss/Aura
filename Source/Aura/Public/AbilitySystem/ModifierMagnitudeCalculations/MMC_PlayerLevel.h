// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"

#include "MMC_PlayerLevel.generated.h"

UCLASS()
class AURA_API UMMC_PlayerLevel : public UGameplayModMagnitudeCalculation
{
    GENERATED_BODY()

public:
    virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;
};
