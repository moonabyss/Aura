// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_CharacterBase.h"

AAG_CharacterBase::AAG_CharacterBase()
{
    PrimaryActorTick.bCanEverTick = false;

    Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
    check(Weapon);
    Weapon->SetupAttachment(GetMesh(), "WeaponHandSocket");
    Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
