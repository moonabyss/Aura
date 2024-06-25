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

UCLASS()
class AURA_API UAG_AttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UAG_AttributeSet();
    virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
    virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
    virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Vital Attributes")
    FGameplayAttributeData Health;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Health);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Vital Attributes")
    FGameplayAttributeData MaxHealth;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, MaxHealth);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Mana", Category = "Vital Attributes")
    FGameplayAttributeData Mana;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, Mana);

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxMana", Category = "Vital Attributes")
    FGameplayAttributeData MaxMana;
    ATTRIBUTE_ACCESSORS(UAG_AttributeSet, MaxMana);

    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

    UFUNCTION()
    void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

    UFUNCTION()
    void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;

private:
    /**
     * Fill Props with Source and Target properties of applied effect
     * @param Props (OUT) container
     */
    void SetEffectProperties(const FGameplayEffectModCallbackData& Data, OUT FEffectProperties& Props) const;
};
