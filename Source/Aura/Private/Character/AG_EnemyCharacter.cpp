// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_EnemyCharacter.h"

AAG_EnemyCharacter::AAG_EnemyCharacter()
{
    PrimaryActorTick.bCanEverTick = true;
    GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
}

void AAG_EnemyCharacter::Tick(float DeltaSeconds)
{
    if (bHighlight)
    {}
}

void AAG_EnemyCharacter::HighlightActor()
{
    bHighlight = true;
}

void AAG_EnemyCharacter::UnHighlightActor()
{
    bHighlight = false;
}
