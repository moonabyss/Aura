// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Singleton/AG_GameplayTags.h"
#include "GameplayTagsManager.h"

FAG_GameplayTags FAG_GameplayTags::GameplayTags;

void FAG_GameplayTags::InitializeNativeGameplayTags()
{
    UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributes.Secondary.Armor"), FString("Reduces damage taken, improves Block chance"));
}
