// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Enemy/AG_EnemyCharacter.h"
#include "Aura/Aura.h"

#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystem/AG_AttributeSet.h"

AAG_EnemyCharacter::AAG_EnemyCharacter()
{
    check(GetMesh());
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

    AbilitySystemComponent = CreateDefaultSubobject<UAG_AbilitySystemComponent>("AbilitySystemComponent");
    check(AbilitySystemComponent);
    AbilitySystemComponent->SetIsReplicated(true);
    AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

    AttributeSet = CreateDefaultSubobject<UAG_AttributeSet>("AttributeSet");
    check(AttributeSet);
}

void AAG_EnemyCharacter::BeginPlay()
{
    Super::BeginPlay();

    AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

void AAG_EnemyCharacter::HighlightActor()
{
    GetMesh()->SetRenderCustomDepth(true);
    GetMesh()->CustomDepthStencilValue = CUSTOM_DEPTH_RED;
    if (Weapon)
    {
        Weapon->SetRenderCustomDepth(true);
        Weapon->CustomDepthStencilValue = CUSTOM_DEPTH_RED;
    }
}

void AAG_EnemyCharacter::UnHighlightActor()
{
    GetMesh()->SetRenderCustomDepth(false);
    if (Weapon)
    {
        Weapon->SetRenderCustomDepth(false);
    }
}
