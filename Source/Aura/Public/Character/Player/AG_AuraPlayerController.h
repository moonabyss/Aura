// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"

#include "AG_AuraPlayerController.generated.h"

struct FGameplayTag;
class UAG_InputConfig;
class IEnemyInterface;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

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

    // TraceHit under cursor
    void CursorTrace();

    // Actor under cursor at last frame
    TObjectPtr<IEnemyInterface> LastActor{nullptr};
    // Actor under cursor in current frame
    TObjectPtr<IEnemyInterface> ThisActor{nullptr};

    void BindAbilityActions(UEnhancedInputComponent* EnhancedInputComponent);

    UFUNCTION()
    void AbilityInputTagPressed(FGameplayTag InputTag);

    UFUNCTION()
    void AbilityInputTagReleased(FGameplayTag InputTag);

    UFUNCTION()
    void AbilityInputTagHeld(FGameplayTag InputTag);

    UPROPERTY(EditDefaultsOnly, Category = "Input")
    TObjectPtr<UAG_InputConfig> InputConfig;
};
