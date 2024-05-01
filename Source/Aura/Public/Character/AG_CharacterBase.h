// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AG_CharacterBase.generated.h"

class USkeletalMeshComponent;

UCLASS(Abstract, NotBlueprintable)
class AURA_API AAG_CharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AAG_CharacterBase();

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon;
};
