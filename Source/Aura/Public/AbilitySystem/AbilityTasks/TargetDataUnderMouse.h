// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "Abilities/Tasks/AbilityTask.h"
#include "CoreMinimal.h"

#include "TargetDataUnderMouse.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMouseTargetDataSignature, const FVector&, Data);

UCLASS()
class AURA_API UTargetDataUnderMouse : public UAbilityTask
{
    GENERATED_BODY()

public:
    UFUNCTION(Category = "Ability|Tasks", BlueprintCallable, meta = (DisplayName = "TargetDataUnderMouse", HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
    static UTargetDataUnderMouse* CreateTargetDataUnderMouse(UGameplayAbility* OwningAbility);

    UPROPERTY(BlueprintAssignable)
    FMouseTargetDataSignature ValidData;

private:
    virtual void Activate() override;
};
