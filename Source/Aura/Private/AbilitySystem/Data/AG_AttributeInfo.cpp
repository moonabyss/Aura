// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/Data/AG_AttributeInfo.h"

DEFINE_LOG_CATEGORY_STATIC(LogAttributeInfo, All, All)

FAuraAttributeInfo UAG_AttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag, bool bLogIfNotFound /*= false*/) const
{
    for (const auto& Info : AttributeInformation)
    {
        if (Info.AttributeTag.MatchesTagExact(AttributeTag))
        {
            return Info;
        }
    }

    if (bLogIfNotFound)
    {
        UE_LOG(LogAttributeInfo, Error, TEXT("Can't find info for AttributeTaf [%s] on AttributeInfo [%s]"), *AttributeTag.ToString(), *GetNameSafe(this));
    }

    return FAuraAttributeInfo();
}
