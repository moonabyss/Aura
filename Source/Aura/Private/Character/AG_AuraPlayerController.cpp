// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAG_AuraPlayerController::AAG_AuraPlayerController()
{
    bReplicates = true;
}

void AAG_AuraPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Get Input Subsystem
    UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    check(InputSubsystem);

    // Set Mapping Context
    check(AuraInputContext);
    InputSubsystem->AddMappingContext(AuraInputContext, 0);

    // Cursor
    bShowMouseCursor = true;
    DefaultMouseCursor = EMouseCursor::Default;

    // Input mode
    FInputModeGameAndUI InputModeData;
    InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
    InputModeData.SetHideCursorDuringCapture(false);
    SetInputMode(InputModeData);
}
