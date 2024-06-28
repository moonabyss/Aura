// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/ModifierMagnitudeCalculations/MMC_PlayerLevel.h"
#include "AbilitySystem/AG_AttributeSet.h"
#include "Interaction/CombatInterface.h"

float UMMC_PlayerLevel::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
    const auto* CombatInterface = Cast<ICombatInterface>(Spec.GetContext().GetSourceObject());
    checkf(CombatInterface, TEXT("%s doesn't implement ICombatInterface"), *Spec.GetContext().GetSourceObject()->GetName());
    return CombatInterface->GetPlayerLevel();
}
