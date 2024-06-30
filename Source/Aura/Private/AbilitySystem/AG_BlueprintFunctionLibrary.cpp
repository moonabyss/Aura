// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "AbilitySystem/AG_BlueprintFunctionLibrary.h"
#include "Character/Player/AG_AuraPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "UI/HUD/AG_HUD.h"
#include "UI/WidgetController/AG_OverlayWidgetController.h"

UAG_OverlayWidgetController* UAG_BlueprintFunctionLibrary::GetOverlayWidgetGontroller(const UObject* WorldContextObject)
{
    auto* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
    if (!PC) return nullptr;
    auto* PS = PC->GetPlayerState<AAG_AuraPlayerState>();
    if (!PS) return nullptr;

    auto* ASC = PS->GetAbilitySystemComponent();
    auto* AS = PS->GetAttributeSet();
    if (auto* AuraHUD = Cast<AAG_HUD>(PC->GetHUD()))
    {
        return AuraHUD->GetOverlayWidgetController(FWidgetControllerParams(PC, PS, ASC, AS));
    }
    return nullptr;
}

UAG_AttributeMenuWidgetController* UAG_BlueprintFunctionLibrary::GetAttributeMenuWidgetGontroller(const UObject* WorldContextObject)
{
    auto* PC = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
    if (!PC) return nullptr;
    auto* PS = PC->GetPlayerState<AAG_AuraPlayerState>();
    if (!PS) return nullptr;

    auto* ASC = PS->GetAbilitySystemComponent();
    auto* AS = PS->GetAttributeSet();
    if (auto* AuraHUD = Cast<AAG_HUD>(PC->GetHUD()))
    {
        return AuraHUD->GetAttributeMenuWidgetController(FWidgetControllerParams(PC, PS, ASC, AS));
    }

    return nullptr;
}
