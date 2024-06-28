// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AbilitySystemInterface.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"

#include "AG_AuraPlayerState.generated.h"

class UAbilitySystemComponent;
class UAttributeSet;

UCLASS()
class AURA_API AAG_AuraPlayerState : public APlayerState, public IAbilitySystemInterface
{
    GENERATED_BODY()

public:
    AAG_AuraPlayerState();

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }  // IAbilitySystemInterface

    /** Initialize struct ActorInfo of Ability System */
    void InitAbilityActorInfo(AActor* Avatar);

    virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }
    int32 GetPlayerLevel() const { return Level; }

private:
    UPROPERTY()
    TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent{nullptr};

    UPROPERTY()
    TObjectPtr<UAttributeSet> AttributeSet{nullptr};

private:
    UPROPERTY(VisibleAnywhere, ReplicatedUsing = OnRep_Level)
    int32 Level{1};

    UFUNCTION()
    void OnRep_Level(int32 OldLevel);
};
