// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Enemy/AG_EnemyCharacter.h"
#include "Aura/Aura.h"

AAG_EnemyCharacter::AAG_EnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;

    check(GetMesh());
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
