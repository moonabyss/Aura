// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "AG_CharacterBase.generated.h"

class USkeletalMeshComponent;
class UAbilitySystemComponent;
class UAttributeSet;

UCLASS(Abstract, NotBlueprintable)
class AURA_API AAG_CharacterBase : public ACharacter, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AAG_CharacterBase();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return nullptr; }  // IAbilitySystemInterface
    virtual UAttributeSet* GetAttributeSet() const { return nullptr; }

protected:
    virtual void BeginPlay() override;

    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon;
};
