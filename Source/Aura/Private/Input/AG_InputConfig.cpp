// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Input/AG_InputConfig.h"
#include "InputAction.h"

DEFINE_LOG_CATEGORY_STATIC(LogInputConfig, All, All)

const UInputAction* UAG_InputConfig::FindAbilityInputActionForTag(const FGameplayTag& InputTag, bool bLogIfNotFound /*= true*/) const
{
    for (const auto& [Action, Tag] : AbilityInputActions)
    {
        if (Action && Tag.MatchesTagExact(InputTag))
        {
            return Action;
        }
    }

    if (bLogIfNotFound)
    {
        UE_LOG(LogInputConfig, Error, TEXT("Can't find AbilityInputAction for InputTag [%s] on InputConfig [%s]"), *InputTag.ToString(), *GetNameSafe(this));
    }

    return nullptr;
}
