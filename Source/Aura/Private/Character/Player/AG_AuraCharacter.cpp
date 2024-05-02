// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Player/AG_AuraCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "Character/Player/AG_AuraPlayerState.h"

AAG_AuraCharacter::AAG_AuraCharacter()
{
    SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
    check(SpringArm);
    SpringArm->SetupAttachment(GetCapsuleComponent());
    SpringArm->TargetArmLength = 750.0f;
    SpringArm->bUsePawnControlRotation = false;
    SpringArm->bEnableCameraLag = true;
    SpringArm->bInheritPitch = false;
    SpringArm->bInheritRoll = false;
    SpringArm->bInheritYaw = false;

    Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
    check(Camera);
    Camera->SetupAttachment(SpringArm);
    Camera->bUsePawnControlRotation = false;

    check(GetCharacterMovement());
    GetCharacterMovement()->bOrientRotationToMovement = true;
    GetCharacterMovement()->RotationRate = FRotator{0.0, 480.0, 0.0};
    GetCharacterMovement()->bConstrainToPlane = true;
    GetCharacterMovement()->bSnapToPlaneAtStart = true;

    bUseControllerRotationPitch = false;
    bUseControllerRotationRoll = false;
    bUseControllerRotationYaw = false;
}

UAbilitySystemComponent* AAG_AuraCharacter::GetAbilitySystemComponent() const
{
    auto* PS = GetPlayerState<AAG_AuraPlayerState>();
    if (!PS) return nullptr;

    return PS->GetAbilitySystemComponent();
}

UAttributeSet* AAG_AuraCharacter::GetAttributeSet() const
{
    auto* PS = GetPlayerState<AAG_AuraPlayerState>();
    if (!PS) return nullptr;

    return PS->GetAttributeSet();
}
