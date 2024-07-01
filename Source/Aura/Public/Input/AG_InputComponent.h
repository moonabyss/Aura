// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "AG_InputConfig.h"
#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"

#include "AG_InputComponent.generated.h"

UCLASS()
class AURA_API UAG_InputComponent : public UEnhancedInputComponent
{
    GENERATED_BODY()

public:
    template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
    void BindAbilityActions(const UAG_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc);
};
template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UAG_InputComponent::BindAbilityActions(const UAG_InputConfig* InputConfig, UserClass* Object, PressedFuncType PressedFunc, ReleasedFuncType ReleasedFunc, HeldFuncType HeldFunc)
{
    check(InputConfig);

    for (const auto& [Action, Tag] : InputConfig->AbilityInputActions)
    {
        if (Action && Tag.IsValid())
        {
            if (PressedFunc)
            {
                BindAction(Action, ETriggerEvent::Started, Object, PressedFunc, Tag);
            }
            if (ReleasedFunc)
            {
                BindAction(Action, ETriggerEvent::Completed, Object, ReleasedFunc, Tag);
            }
            if (HeldFunc)
            {
                BindAction(Action, ETriggerEvent::Triggered, Object, HeldFunc, Tag);
            }
        }
    }
}
