// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Character/Player/AG_AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "GameplayTagContainer.h"
// #include "Input/AG_InputComponent.h"
#include "AbilitySystem/AG_AbilitySystemComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AuraGameplayTags.h"
#include "Components/SplineComponent.h"
#include "EnhancedInputComponent.h"
#include "Input/AG_InputConfig.h"
#include "Interaction/EnemyInterface.h"
#include "NavigationPath.h"
#include "NavigationSystem.h"

AAG_AuraPlayerController::AAG_AuraPlayerController()
{
    bReplicates = true;

    SplineAutoPath = CreateDefaultSubobject<USplineComponent>("Spline");
}

void AAG_AuraPlayerController::PlayerTick(float DeltaTime)
{
    Super::PlayerTick(DeltaTime);

    CursorTrace();
    AutoRun();
}

void AAG_AuraPlayerController::BeginPlay()
{
    Super::BeginPlay();

    // Get Input Subsystem
    UEnhancedInputLocalPlayerSubsystem* InputSubsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

    // Set Mapping Context
    if (InputSubsystem && AuraInputContext)
    {
        InputSubsystem->AddMappingContext(AuraInputContext, 0);
    }

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
    /*
    UAG_InputComponent* AuraInputComponent = CastChecked<UAG_InputComponent>(InputComponent);
    AuraInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
    AuraInputComponent->BindAbilityActions(InputConfig, this, &ThisClass::AbilityInputTagPressed, &ThisClass::AbilityInputTagReleased, &ThisClass::AbilityInputTagHeld);
    */
    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ThisClass::Move);
    BindAbilityActions(EnhancedInputComponent);
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
    GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
    if (!CursorHit.bBlockingHit)
    {
        if (LastActor)
        {
            LastActor->UnHighlightActor();
        }
        LastActor = nullptr;
        ThisActor = nullptr;
        return;
    }

    LastActor = ThisActor;
    ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

    if (LastActor != ThisActor)
    {
        if (LastActor)
        {
            LastActor->UnHighlightActor();
        }
        if (ThisActor)
        {
            ThisActor->HighlightActor();
        }
    }
}

void AAG_AuraPlayerController::BindAbilityActions(UEnhancedInputComponent* EnhancedInputComponent)
{
    check(InputConfig);

    for (const auto& [Action, Tag] : InputConfig->AbilityInputActions)
    {
        if (Action && Tag.IsValid())
        {
            EnhancedInputComponent->BindAction(Action, ETriggerEvent::Started, this, &ThisClass::AbilityInputTagPressed, Tag);
            EnhancedInputComponent->BindAction(Action, ETriggerEvent::Completed, this, &ThisClass::AbilityInputTagReleased, Tag);
            EnhancedInputComponent->BindAction(Action, ETriggerEvent::Triggered, this, &ThisClass::AbilityInputTagHeld, Tag);
        }
    }
}

void AAG_AuraPlayerController::AbilityInputTagPressed(FGameplayTag InputTag)
{
    if (InputTag.MatchesTagExact(FAuraGameplayTags::Get().InputTag_LMB))
    {
        bTargeting = ThisActor ? true : false;
        bAutoRunning = false;
    }
}

void AAG_AuraPlayerController::AbilityInputTagReleased(FGameplayTag InputTag)
{
    if (!InputTag.MatchesTagExact(FAuraGameplayTags::Get().InputTag_LMB))
    {
        if (auto* ASC = GetAuraASC())
        {
            ASC->AbilityInputTagReleased(InputTag);
        }
        return;
    }

    if (bTargeting)
    {
        if (auto* ASC = GetAuraASC())
        {
            ASC->AbilityInputTagReleased(InputTag);
        }
    }
    else
    {
        const auto* ControlledPawn = GetPawn();
        if (FollowTime <= ShortPressThreshold && ControlledPawn)
        {
            if (auto* NavPath = UNavigationSystemV1::FindPathToLocationSynchronously(this, ControlledPawn->GetActorLocation(), CachedDestination))
            {
                SplineAutoPath->ClearSplinePoints();
                for (const auto& PointLoc : NavPath->PathPoints)
                {
                    SplineAutoPath->AddSplineWorldPoint(PointLoc);
                }
                if (NavPath->PathPoints.Num() > 0)
                {
                    CachedDestination = NavPath->PathPoints[NavPath->PathPoints.Num() - 1];
                    bAutoRunning = true;
                }
            }
        }
        FollowTime = 0.0f;
        bTargeting = false;
    }
}

void AAG_AuraPlayerController::AbilityInputTagHeld(FGameplayTag InputTag)
{
    if (!InputTag.MatchesTagExact(FAuraGameplayTags::Get().InputTag_LMB))
    {
        if (auto* ASC = GetAuraASC())
        {
            ASC->AbilityInputTagHeld(InputTag);
        }
        return;
    }

    if (bTargeting)
    {
        if (auto* ASC = GetAuraASC())
        {
            ASC->AbilityInputTagHeld(InputTag);
        }
    }
    else
    {
        FollowTime += GetWorld()->GetDeltaSeconds();

        if (CursorHit.bBlockingHit)
        {
            CachedDestination = CursorHit.ImpactPoint;
        }

        if (auto* ControlledPawn = GetPawn())
        {
            const FVector WorldDirection = (CachedDestination - ControlledPawn->GetActorLocation()).GetSafeNormal();
            ControlledPawn->AddMovementInput(WorldDirection);
        }
    }
}

UAG_AbilitySystemComponent* AAG_AuraPlayerController::GetAuraASC()
{
    if (!AuraAbilitySystemComponent)
    {
        AuraAbilitySystemComponent = Cast<UAG_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()));
    }
    return AuraAbilitySystemComponent;
}

void AAG_AuraPlayerController::AutoRun()
{
    if (!bAutoRunning) return;

    if (auto* ControlledPawn = GetPawn())
    {
        const FVector LocationOnSpline = SplineAutoPath->FindLocationClosestToWorldLocation(ControlledPawn->GetActorLocation(), ESplineCoordinateSpace::World);
        const FVector Direction = SplineAutoPath->FindDirectionClosestToWorldLocation(LocationOnSpline, ESplineCoordinateSpace::World);
        ControlledPawn->AddMovementInput(Direction);

        const float DistanceToDestination = (LocationOnSpline - CachedDestination).Length();
        if (DistanceToDestination <= AutoRunAcceptanceRadius)
        {
            bAutoRunning = false;
        }
    }
}
