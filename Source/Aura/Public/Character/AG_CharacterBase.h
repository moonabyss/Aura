// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AG_CharacterBase.generated.h"

UCLASS(Abstract)
class AURA_API AAG_CharacterBase : public ACharacter
{
    GENERATED_BODY()

public:
    AAG_CharacterBase();

protected:
    virtual void BeginPlay() override;
};
