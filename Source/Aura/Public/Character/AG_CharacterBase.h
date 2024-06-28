// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "Interaction/CombatInterface.h"

#include "AG_CharacterBase.generated.h"

class USkeletalMeshComponent;
class UAbilitySystemComponent;
class UAttributeSet;
class UGameplayEffect;

UCLASS(Abstract, NotBlueprintable)
class AURA_API AAG_CharacterBase : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
    GENERATED_BODY()

public:
    AAG_CharacterBase();

    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }  // IAbilitySystemInterface
    virtual int32 GetPlayerLevel() const override { return 0; }                                                     // ICombatInterface
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

    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultPrimaryAttributes{nullptr};

    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultSecondaryAttributes{nullptr};

    UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Attributes")
    TSubclassOf<UGameplayEffect> DefaultVitalAttributes{nullptr};

    void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> GameplayEffectClass, float Level = 1.0f) const;
    void InitializeDefaultAttributes() const;
};
