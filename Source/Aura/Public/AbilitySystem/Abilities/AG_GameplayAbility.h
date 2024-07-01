// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "Abilities/GameplayAbility.h"
#include "CoreMinimal.h"

#include "AG_GameplayAbility.generated.h"

UCLASS()
class AURA_API UAG_GameplayAbility : public UGameplayAbility
{
    GENERATED_BODY()

public:
    UPROPERTY(EditDefaultsOnly, Category = "Input")
    FGameplayTag StartupInputTag;
};
