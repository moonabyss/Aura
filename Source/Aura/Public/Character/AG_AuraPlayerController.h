// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "AG_AuraPlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class AURA_API AAG_AuraPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AAG_AuraPlayerController();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    TObjectPtr<UInputMappingContext> AuraInputContext;
};
