// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags
 *
 * Singleton containing native Gameplay Tags
 */

struct FAuraGameplayTags
{
public:
    static const FAuraGameplayTags& Get() { return GameplayTags; }
    static void InitializeNativeGameplayTags();

    FGameplayTag Attrubutes_Primary_Strength;
    FGameplayTag Attrubutes_Primary_Intelligence;
    FGameplayTag Attrubutes_Primary_Resilience;
    FGameplayTag Attrubutes_Primary_Vigor;

    FGameplayTag Attrubutes_Secondary_Armor;
    FGameplayTag Attrubutes_Secondary_ArmorPenetration;
    FGameplayTag Attrubutes_Secondary_BlockChance;
    FGameplayTag Attrubutes_Secondary_CriticalHitChance;
    FGameplayTag Attrubutes_Secondary_CriticalHitDamage;
    FGameplayTag Attrubutes_Secondary_CriticalHitResistance;
    FGameplayTag Attrubutes_Secondary_HealthRegeneration;
    FGameplayTag Attrubutes_Secondary_ManaRegeneration;
    FGameplayTag Attrubutes_Secondary_MaxHealth;
    FGameplayTag Attrubutes_Secondary_MaxMana;

private:
    static FAuraGameplayTags GameplayTags;
};
