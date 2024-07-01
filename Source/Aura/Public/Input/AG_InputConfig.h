// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "AG_InputConfig.generated.h"

struct FGameplayTag;
class UInputAction;

USTRUCT(BlueprintType)
struct FAuraInputAction
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly)
    const UInputAction* InputAction = nullptr;

    UPROPERTY(EditDefaultsOnly)
    FGameplayTag InputTag = FGameplayTag();
};

UCLASS()
class AURA_API UAG_InputConfig : public UDataAsset
{
    GENERATED_BODY()

public:
    const UInputAction* FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogIfNotFound = true) const;

    UPROPERTY(EditDefaultsOnly)
    TArray<FAuraInputAction> AbilityInputActions;
};
