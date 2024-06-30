// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

#include "AG_Types.generated.h"

class UAG_UserWidget;

// DEFINITIONS
#define CUSTOM_DEPTH_RED 250

// STRUCTS
USTRUCT(BlueprintType)
struct FUIWidgetRow : public FTableRowBase
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FGameplayTag MessageTag = FGameplayTag();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    FText Message = FText();

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    TSubclassOf<UAG_UserWidget> MessageWidget{nullptr};

    UPROPERTY(EditAnywhere, BlueprintReadOnly)
    UTexture2D* Image{nullptr};
};

// DELEGATES
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMessageWidgetRowSignature, const FUIWidgetRow&, Row);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeInfoSignature, const FAuraAttributeInfo&, Info);

UCLASS()
class AURA_API UAG_Types : public UObject
{
    GENERATED_BODY()
};
