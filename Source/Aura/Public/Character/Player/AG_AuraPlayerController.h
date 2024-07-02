// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "AG_AuraPlayerController.generated.h"

struct FGameplayTag;
struct FInputActionValue;
class IEnemyInterface;
class UInputMappingContext;
class UInputAction;
class USplineComponent;
class UAG_AbilitySystemComponent;
class UAG_InputConfig;

UCLASS()
class AURA_API AAG_AuraPlayerController : public APlayerController
{
    GENERATED_BODY()

public:
    AAG_AuraPlayerController();
    virtual void PlayerTick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;

private:
    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputMappingContext> AuraInputContext;

    UPROPERTY(EditAnywhere, Category = "Input")
    TObjectPtr<UInputAction> MoveAction;

    void Move(const FInputActionValue& InputActionValue);

    FHitResult CursorHit;

    // TraceHit under cursor
    void CursorTrace();

    // Actor under cursor at last frame
    TObjectPtr<IEnemyInterface> LastActor{nullptr};
    // Actor under cursor in current frame
    TObjectPtr<IEnemyInterface> ThisActor{nullptr};

    void BindAbilityActions(UEnhancedInputComponent* EnhancedInputComponent);

    void AbilityInputTagPressed(FGameplayTag InputTag);
    void AbilityInputTagReleased(FGameplayTag InputTag);
    void AbilityInputTagHeld(FGameplayTag InputTag);

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UAG_InputConfig> InputConfig = nullptr;

    UPROPERTY()
    TObjectPtr<UAG_AbilitySystemComponent> AuraAbilitySystemComponent;

    UAG_AbilitySystemComponent* GetAuraASC();

    FVector CachedDestination = FVector::ZeroVector;
    float FollowTime = 0.0f;
    float ShortPressThreshold = 0.5f;
    bool bAutoRunning = false;
    bool bTargeting = false;

    UPROPERTY(EditDefaultsOnly)
    float AutoRunAcceptanceRadius = 50.0f;

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<USplineComponent> SplineAutoPath = nullptr;

    void AutoRun();
};
