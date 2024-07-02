// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "Character/AG_CharacterBase.h"
#include "CoreMinimal.h"

#include "AG_AuraCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS(Blueprintable)
class AURA_API AAG_AuraCharacter : public AAG_CharacterBase
{
    GENERATED_BODY()

public:
    AAG_AuraCharacter();

    virtual void PossessedBy(AController* NewController) override;
    virtual void OnRep_PlayerState() override;
    virtual int32 GetPlayerLevel() const override;             // ICombatInterface
    virtual FVector GetCombatSocketLocation() const override;  // ICombatInterface

protected:
    UPROPERTY(EditAnywhere, Category = "Components")
    TObjectPtr<USpringArmComponent> SpringArm{nullptr};

    UPROPERTY(EditAnywhere, Category = "Components")
    TObjectPtr<UCameraComponent> Camera{nullptr};

    virtual void InitAbilityActorInfo() override;

    UPROPERTY(EditDefaultsOnly, Category = "Combat")
    FName WeaponTipSocketName = FName();

private:
    void InitOverlay() const;
};
