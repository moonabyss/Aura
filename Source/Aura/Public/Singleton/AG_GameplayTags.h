// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AG_GameplayTags
 *
 * Singleton containg native Gameplay Tags
 */

struct FAG_GameplayTags
{
public:
    static const FAG_GameplayTags& Get() { return GameplayTags; }
    static void InitializeNativeGameplayTags();

private:
    static FAG_GameplayTags GameplayTags;
};
