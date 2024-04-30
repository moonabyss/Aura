// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_CharacterBase.h"

AAG_CharacterBase::AAG_CharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;
}

void AAG_CharacterBase::BeginPlay()
{
    Super::BeginPlay();
}
