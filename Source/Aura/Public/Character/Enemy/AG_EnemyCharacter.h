// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "Character/AG_CharacterBase.h"
#include "CoreMinimal.h"

#include "Interaction/EnemyInterface.h"

#include "AG_EnemyCharacter.generated.h"

UCLASS(Blueprintable)
class AURA_API AAG_EnemyCharacter : public AAG_CharacterBase, public IEnemyInterface
{
    GENERATED_BODY()

public:
    AAG_EnemyCharacter();

    virtual void HighlightActor() override;                          // IEnemyInterface
    virtual void UnHighlightActor() override;                        // IEnemyInterface
    virtual int32 GetPlayerLevel() const override { return Level; }  // ICombatInterface

protected:
    virtual void BeginPlay() override;

    virtual void InitAbilityActorInfo() override;

private:
    UPROPERTY(EditAnywhere, Category = "Character Class Defaults")
    int32 Level{1};
};
