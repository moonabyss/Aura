// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/AG_AuraPlayerController.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"

#include "Interaction/EnemyInterface.h"

AAG_AuraPlayerController::AAG_AuraPlayerController()
{
    bReplicates = true;
}

void AAG_AuraPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    CursorTrace();
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

void AAG_AuraPlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    // Bind Input
    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
}

void AAG_AuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
    APawn* ControlledPawn = GetPawn();
    if (!ControlledPawn) return;

    // Get rotation
    const FRotator Rotation = GetControlRotation();
    const FRotator YawRotation{0.0, Rotation.Yaw, 0.0};

    // Get move vectors
    const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
    const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

    // Add movement
    const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
    ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
    ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
}

void AAG_AuraPlayerController::CursorTrace()
{
    FHitResult CursorHit;
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if (CursorHit.bBlockingHit)
    {
        ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
        if (ThisActor)
        {
            ThisActor->HighlightActor();
        }
        if (LastActor && LastActor != ThisActor)
        {
            LastActor->UnHighlightActor();
        }
    }
    else
    {
        ThisActor = nullptr;
        if (LastActor)
        {
            LastActor->UnHighlightActor();
            LastActor = nullptr;
        }
    }
    LastActor = ThisActor;
}
