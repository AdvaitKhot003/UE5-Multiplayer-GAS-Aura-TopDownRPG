// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedInputComponent.h"
#include "GameplayTagContainer.h"
#include "Data/AuraInputConfig.h"
#include "AuraEnhancedInput.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UAuraEnhancedInput : public UEnhancedInputComponent
{
	GENERATED_BODY()
	
public:
	template<class UserObject, typename CallbackFunction>
	void BindNativeInputAction(const UAuraInputConfig* InInputConfig, const FGameplayTag& InInputTag,
		ETriggerEvent TriggerEvent, UserObject* Object, CallbackFunction Function);
	
	template<class UserObject, typename CallbackPressed, typename CallbackHeld, typename CallbackReleased>
	void BindAbilityInputAction(const UAuraInputConfig* InInputConfig, UserObject* Object,
		CallbackPressed PressedFunction, CallbackHeld HeldFunction, CallbackReleased ReleasedFunction);
};

template <class UserObject, typename CallbackFunction>
void UAuraEnhancedInput::BindNativeInputAction(const UAuraInputConfig* InInputConfig, const FGameplayTag& InInputTag,
	ETriggerEvent TriggerEvent, UserObject* Object, CallbackFunction Function)
{
	if (!InInputConfig) return;
	
	if (const UInputAction* InputAction = InInputConfig->FindNativeInputActionByTag(InInputTag))
	{
		BindAction(InputAction, TriggerEvent, Object, Function);
	}
}

template <class UserObject, typename CallbackPressed, typename CallbackHeld, typename CallbackReleased>
void UAuraEnhancedInput::BindAbilityInputAction(const UAuraInputConfig* InInputConfig, UserObject* Object,
	CallbackPressed PressedFunction, CallbackHeld HeldFunction, CallbackReleased ReleasedFunction)
{
	if (!InInputConfig) return;
	
	for (const FAuraInputActionConfig& Config : InInputConfig->AbilityInputActionConfigs)
	{
		if (!Config.IsValid()) continue;
		
		BindAction(Config.InputAction, ETriggerEvent::Started, Object, PressedFunction, Config.InputTag);
		BindAction(Config.InputAction, ETriggerEvent::Triggered, Object, HeldFunction, Config.InputTag);
		BindAction(Config.InputAction, ETriggerEvent::Completed, Object, ReleasedFunction, Config.InputTag);
		BindAction(Config.InputAction, ETriggerEvent::Canceled, Object, ReleasedFunction, Config.InputTag);
	}
}
