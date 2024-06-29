// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
    GameplayTags.Attrubutes_Primary_Strength =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Strength"), FString("Increases physical damage"));
    GameplayTags.Attrubutes_Primary_Intelligence =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Intelligence"), FString("Increases magical damage"));
    GameplayTags.Attrubutes_Primary_Resilience =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Resilience"), FString("Increases Armor and Armor Penetration"));
    GameplayTags.Attrubutes_Primary_Vigor =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Primary.Vigor"), FString("Increases Health"));

    GameplayTags.Attrubutes_Secondary_Armor =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block chance"));
    GameplayTags.Attrubutes_Secondary_ArmorPenetration =
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ArmorPenetration"), FString("Ignores percentage of enemy armor, increases Critical Hit Chance"));
    GameplayTags.Attrubutes_Secondary_BlockChance =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.BlockChance"), FString("Chance to cut incoming damage in half"));
    GameplayTags.Attrubutes_Secondary_CriticalHitChance =
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitChance"), FString("Chance to double damage plus critical hit bonus"));
    GameplayTags.Attrubutes_Secondary_CriticalHitDamage =
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitDamage"), FString("Bonus damage added when a critical hit is scored"));
    GameplayTags.Attrubutes_Secondary_CriticalHitResistance =
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.CriticalHitResistance"), FString("Reduses Critical Hit Chance of attacking enemies"));
    GameplayTags.Attrubutes_Secondary_HealthRegeneration =
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.HealthRegeneration"), FString("Amount of Health regenerated every 1 second"));
    GameplayTags.Attrubutes_Secondary_ManaRegeneration =
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.ManaRegeneration"), FString("Amount of Mana regenerated every 1 second"));
    GameplayTags.Attrubutes_Secondary_MaxHealth =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxHealth"), FString("Maximum amount of Health obtainable"));
    GameplayTags.Attrubutes_Secondary_MaxMana =  //
        UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.MaxMana"), FString("Maximum amount of Mana obtainable"));
}
