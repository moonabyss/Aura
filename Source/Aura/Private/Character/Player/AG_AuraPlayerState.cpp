// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Player/AG_AuraPlayerState.h"

#include "Net/UnrealNetwork.h"

#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystem/AG_AttributeSet.h"

AAG_AuraPlayerState::AAG_AuraPlayerState()
{
    AbilitySystemComponent = CreateDefaultSubobject<UAG_AbilitySystemComponent>("AbilitySystemComponent");
    check(AbilitySystemComponent);
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

    AttributeSet = CreateDefaultSubobject<UAG_AttributeSet>("AttributeSet");
    check(AttributeSet);

    NetUpdateFrequency = 100.0f;
}

void AAG_AuraPlayerState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME(AAG_AuraPlayerState, Level);
}

void AAG_AuraPlayerState::InitAbilityActorInfo(AActor* Avatar)
{
    AbilitySystemComponent->InitAbilityActorInfo(this, Avatar);
}

void AAG_AuraPlayerState::OnRep_Level(int32 OldLevel) {}
