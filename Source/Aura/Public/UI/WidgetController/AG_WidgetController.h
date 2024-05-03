// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AG_WidgetController.generated.h"

class UAttributeSet;
class UAbilitySystemComponent;

UCLASS()
class AURA_API UAG_WidgetController : public UObject
{
    GENERATED_BODY()

protected:
    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    TObjectPtr<APlayerController> PlayerController;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    TObjectPtr<APlayerState> PlayerState;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

    UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
    TObjectPtr<UAttributeSet> AttributeSet;
};
