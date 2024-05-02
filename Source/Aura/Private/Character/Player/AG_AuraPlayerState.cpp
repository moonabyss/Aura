// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Player/AG_AuraPlayerState.h"

#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystem/AG_AttributeSet.h"

AAG_AuraPlayerState::AAG_AuraPlayerState()
{
    AbilitySystemComponent = CreateDefaultSubobject<UAG_AbilitySystemComponent>("AbilitySystemComponent");
    check(AbilitySystemComponent);
    AbilitySystemComponent->SetIsReplicated(true);

    AttributeSet = CreateDefaultSubobject<UAG_AttributeSet>("AttributeSet");
    check(AttributeSet);

    NetUpdateFrequency = 100.0f;
}
