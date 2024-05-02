// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Player/AG_AuraCharacter.h"
#include "AbilitySystem/AG_AbilitySystemComponent.h"
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

void AAG_AuraCharacter::PossessedBy(AController* NewController)
{
    Super::PossessedBy(NewController);

    // Init ability actor info for the server
    InitAbilityActorInfo();
}

void AAG_AuraCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    // Init ability actor info for the client
    InitAbilityActorInfo();
}

void AAG_AuraCharacter::InitAbilityActorInfo()
{
    if (auto* AuraPlayerState = GetPlayerState<AAG_AuraPlayerState>())
    {
        AuraPlayerState->InitAbilityActorInfo(this);
        AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
        AttributeSet = AuraPlayerState->GetAttributeSet();
    }
}
