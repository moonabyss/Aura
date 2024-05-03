// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AttributeSet.h"
#include "CoreMinimal.h"

#include "AG_AttributeSet.generated.h"

UCLASS()
class AURA_API UAG_AttributeSet : public UAttributeSet
{
    GENERATED_BODY()

public:
    UAG_AttributeSet();
    virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Health", Category = "Vital Attributes")
    FGameplayAttributeData Health;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxHealth", Category = "Vital Attributes")
    FGameplayAttributeData MaxHealth;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_Mana", Category = "Vital Attributes")
    FGameplayAttributeData Mana;

    UPROPERTY(BlueprintReadOnly, ReplicatedUsing = "OnRep_MaxMana", Category = "Vital Attributes")
    FGameplayAttributeData MaxMana;

    UFUNCTION()
    void OnRep_Health(const FGameplayAttributeData& OldHealth) const;

    UFUNCTION()
    void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

    UFUNCTION()
    void OnRep_Mana(const FGameplayAttributeData& OldMana) const;

    UFUNCTION()
    void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};
