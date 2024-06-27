// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Player/AG_AuraCharacter.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "Character/Player/AG_AuraPlayerController.h"
#include "Character/Player/AG_AuraPlayerState.h"
#include "UI/HUD/AG_HUD.h"
#include "UI/WidgetController/AG_WidgetController.h"

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
    // Show HUD for local player
    if (IsLocallyControlled())
    {
        InitOverlay();
    }
}

void AAG_AuraCharacter::OnRep_PlayerState()
{
    Super::OnRep_PlayerState();

    // Init ability actor info for the client
    InitAbilityActorInfo();
    // Show HUD for clients
    InitOverlay();
}

void AAG_AuraCharacter::InitAbilityActorInfo()
{
    if (auto* AuraPlayerState = GetPlayerState<AAG_AuraPlayerState>())
    {
        AuraPlayerState->InitAbilityActorInfo(this);
        AttributeSet = AuraPlayerState->GetAttributeSet();
        AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
        if (auto* ASC = Cast<UAG_AbilitySystemComponent>(AbilitySystemComponent))
        {
            ASC->AbilityActorInfoSet();
        }
    }
    InitializeDefaultAttributes();
}

void AAG_AuraCharacter::InitOverlay() const
{
    auto* PC = Cast<AAG_AuraPlayerController>(GetController());
    auto* PS = GetPlayerState<AAG_AuraPlayerState>();
    if (PC && PS)
    {
        if (auto* AuraHUD = Cast<AAG_HUD>(PC->GetHUD()))
        {
            AuraHUD->InitOverlay(FWidgetControllerParams(PC, PS, AbilitySystemComponent, AttributeSet));
        }
    }
}
