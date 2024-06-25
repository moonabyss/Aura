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

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }  // IAbilitySystemInterface
    virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
    UPROPERTY(EditAnywhere, Category = "Combat")
    TObjectPtr<USkeletalMeshComponent> Weapon{nullptr};

    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{nullptr};

    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet{nullptr};

    /** Initialize struct ActorInfo of Ability System */
    virtual void InitAbilityActorInfo() {};
};
