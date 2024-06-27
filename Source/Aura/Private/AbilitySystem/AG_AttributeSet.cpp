// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/AG_AttributeSet.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UAG_AttributeSet::UAG_AttributeSet()
{
    InitHealth(50.0f);
    InitMaxHealth(100.0f);
    InitMana(20.0f);
    InitMaxMana(50.0f);
}

void UAG_AttributeSet::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);

    DOREPLIFETIME_CONDITION_NOTIFY(UAG_AttributeSet, Health, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAG_AttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAG_AttributeSet, Mana, COND_None, REPNOTIFY_Always);
    DOREPLIFETIME_CONDITION_NOTIFY(UAG_AttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}

void UAG_AttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAG_AttributeSet, Health, OldHealth);
}

void UAG_AttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAG_AttributeSet, MaxHealth, OldMaxHealth);
}

void UAG_AttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAG_AttributeSet, Mana, OldMana);
}

void UAG_AttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
    GAMEPLAYATTRIBUTE_REPNOTIFY(UAG_AttributeSet, MaxMana, OldMaxMana);
}

void UAG_AttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
    /**
     * Вызывается после применения GameEffect или вызова SetAttribute
     * результатом работы будет новое значение CurrentValue
     * NewValue = BaseValue = новое значение
     * GetAttribute() = CurrentValue = старое значение
     */
    Super::PreAttributeChange(Attribute, NewValue);

    if (Attribute == GetHealthAttribute())
    {
        /*
        float BaseHealth = Health.GetBaseValue();
        float CurrentHealth = Health.GetCurrentValue();
        UE_LOG(LogTemp, Warning, TEXT("PreAttributeChange: NewValue before clamping: %f"), NewValue);
        UE_LOG(LogTemp, Warning, TEXT("PreAttributeChange: BaseHealth: %f, CurrentHealth: %f"), BaseHealth, CurrentHealth);
        UE_LOG(LogTemp, Warning, TEXT("PreAttributeChange: GetHealth(): %f"), GetHealth());
        */
        // NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
        /*
        BaseHealth = Health.GetBaseValue();
        CurrentHealth = Health.GetCurrentValue();
        UE_LOG(LogTemp, Warning, TEXT("PreAttributeChange: NewValue after clamping: %f"), NewValue);
        UE_LOG(LogTemp, Warning, TEXT("PreAttributeChange: BaseHealth: %f, CurrentHealth: %f"), BaseHealth, CurrentHealth);
        UE_LOG(LogTemp, Warning, TEXT("PreAttributeChange: GetHealth(): %f"), GetHealth());
        */
    }
    if (Attribute == GetManaAttribute())
    {
        NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMana());
    }
    /**
     * После этой функции, но до вызова PostGameplayEffectExecute()
     * в CurrentAttribute присваивается значение NewValue
     * GetAttribute() = CurrentValue = NewValue
     * BaseValue не изменится
     */
}

void UAG_AttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
    /**
     * Вызвается после изменения аттрибута
     * В этом месте GetAttribute() = CurrentValue = NewValue из PreAttributeChange
     * BaseValue = все еще новое значение;
     */
    Super::PostGameplayEffectExecute(Data);

    FEffectProperties EffectProps;
    SetEffectProperties(Data, EffectProps);

    if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        /*
        float BaseHealth = Health.GetBaseValue();
        float CurrentHealth = Health.GetCurrentValue();
        UE_LOG(LogTemp, Warning, TEXT("PostGameplayEffectExecute: BaseHealth: %f, CurrentHealth: %f"), BaseHealth, CurrentHealth);
        UE_LOG(LogTemp, Warning, TEXT("PostGameplayEffectExecute: GetHealth(): %f"), GetHealth());
        */
        /**
         * меняет BaseValue
         * вызывает PreAttributeChange()
         * после этого вызова CurrentValue = BaseValue или как изменим в PreAttributeChange()
         * клампить достаточно в этом месте
         */
        SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
        /*
        BaseHealth = Health.GetBaseValue();
        CurrentHealth = Health.GetCurrentValue();
        UE_LOG(LogTemp, Warning, TEXT("PostGameplayEffectExecute: BaseHealth: %f, CurrentHealth: %f"), BaseHealth, CurrentHealth);
        UE_LOG(LogTemp, Warning, TEXT("PostGameplayEffectExecute: GetHealth(): %f"), GetHealth());
        UE_LOG(LogTemp, Warning, TEXT("----------------------------------------------------------------------------"));
        */
    }
    if (Data.EvaluatedData.Attribute == GetManaAttribute())
    {
        SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));
    }
}

void UAG_AttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data, OUT FEffectProperties& Props) const
{
    // Source - couser of the effect, Target - target of the effect (owner of this AS)
    Props.EffectContextHandle = Data.EffectSpec.GetContext();

    // Source
    Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();
    if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
    {
        Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
        Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
        if (!Props.SourceController && Props.SourceAvatarActor)
        {
            if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
            {
                Props.SourceController = Pawn->GetController();
            }
        }
        if (Props.SourceController)
        {
            Props.SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
        }
    }

    // Target
    if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
    {
        Props.TargetASC = &Data.Target;
        Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
        Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
        Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
    }
}
