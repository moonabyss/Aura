// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GameplayTagContainer.h"

#include "AG_AttributeInfo.generated.h"

USTRUCT(BlueprintType)
struct FAuraAttributeInfo
{
    GENERATED_BODY()

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FGameplayTag AttributeTag = FGameplayTag();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText AttributeName = FText();

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    FText AttributeDescription = FText();

    UPROPERTY(BlueprintReadOnly)
    float AttributeValue = 0.0f;
};

UCLASS()
class AURA_API UAG_AttributeInfo : public UDataAsset
{
    GENERATED_BODY()

public:
    FAuraAttributeInfo FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogIfNotFound = false) const;

    UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
    TArray<FAuraAttributeInfo> AttributeInformation;
};
