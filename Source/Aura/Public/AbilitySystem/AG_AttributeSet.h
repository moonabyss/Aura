// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "CoreMinimal.h"

#include "AG_AttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName)           \
    GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
    GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName)               \
    GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName)               \
    GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

USTRUCT()
struct FEffectProperties
{
    GENERATED_BODY()

    FEffectProperties() {}

    FGameplayEffectContextHandle EffectContextHandle;

    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> SourceASC{nullptr};

    UPROPERTY()
    TObjectPtr<AActor> SourceAvatarActor{nullptr};

    UPROPERTY()
    TObjectPtr<AController> SourceController{nullptr};

    UPROPERTY()
    TObjectPtr<ACharacter> SourceCharacter{nullptr};

    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> TargetASC{nullptr};

    UPROPERTY()
    TObjectPtr<AActor> TargetAvatarActor{nullptr};

    UPROPERTY()
    TObjectPtr<AController> TargetController{nullptr};

    UPROPERTY()
    TObjectPtr<ACharacter> TargetCharacter{nullptr};
};

template <class T>
using TStaticFuncPtr = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

UCLASS()
class AURA_API UAG_AttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UAG_AttributeSet();
    virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    TMap<FGameplayTag, TStaticFuncPtr<FGameplayAttribute()>> TagsToAttributes;

    /**
     * Primary Attributes
     */

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Strength", Category = "Attributes|Primary Attributes")
    FGameplayAttributeData Strength;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Strength);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Intelligence", Category = "Attributes|Primary Attributes")
    FGameplayAttributeData Intelligence;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Intelligence);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Resilience", Category = "Attributes|Primary Attributes")
    FGameplayAttributeData Resilience;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Resilience);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Vigor", Category = "Attributes|Primary Attributes")
    FGameplayAttributeData Vigor;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Vigor);

    /**
     * Secondary Attributes
     */

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Armor", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData Armor;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Armor);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_ArmorPenetration", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData ArmorPenetration;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, ArmorPenetration);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_BlockChance", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData BlockChance;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, BlockChance);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_CriticalHitChance", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData CriticalHitChance;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, CriticalHitChance);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_CriticalHitDamage", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData CriticalHitDamage;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, CriticalHitDamage);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_CriticalHitResistance", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData CriticalHitResistance;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, CriticalHitResistance);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_HealthRegeneration", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData HealthRegeneration;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, HealthRegeneration);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_ManaRegeneration", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData ManaRegeneration;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, ManaRegeneration);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, MaxHealth);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxMana", Category = "Attributes|Secondary Attributes")
    FGameplayAttributeData MaxMana;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, MaxMana);

    /**
     * Vital Attributes
     */

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Attributes|Vital Attributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Health);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Mana", Category = "Attributes|Vital Attributes")
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Mana);

    UFUNCTION()
    void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;

    UFUNCTION()
    void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;

    UFUNCTION()
    void OnRep_Resilience(const FGameplayAttributeData& OldResilience) const;

    UFUNCTION()
    void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;

    UFUNCTION()
    void OnRep_Armor(const FGameplayAttributeData& OldArmor) const;

    UFUNCTION()
    void OnRep_ArmorPenetration(const FGameplayAttributeData& OldArmorPenetration) const;

    UFUNCTION()
    void OnRep_BlockChance(const FGameplayAttributeData& OldBlockChance) const;

    UFUNCTION()
    void OnRep_CriticalHitChance(const FGameplayAttributeData& OldCriticalHitChance) const;

    UFUNCTION()
    void OnRep_CriticalHitDamage(const FGameplayAttributeData& OldCriticalHitDamage) const;

    UFUNCTION()
    void OnRep_CriticalHitResistance(const FGameplayAttributeData& OldCriticalHitResistance) const;

    UFUNCTION()
    void OnRep_HealthRegeneration(const FGameplayAttributeData& OldHealthRegeneration) const;

    UFUNCTION()
    void OnRep_ManaRegeneration(const FGameplayAttributeData& OldManaRegeneration) const;

    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

    UFUNCTION()
    void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

    UFUNCTION()
    void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

private:
    /**
     * Fill Props with Source and Target properties of applied effect
     * @param Props (OUT) container
     */
    void SetEffectProperties(const FGameplayEffectModCallbackData& Data, OUT FEffectProperties& Props) const;
};
