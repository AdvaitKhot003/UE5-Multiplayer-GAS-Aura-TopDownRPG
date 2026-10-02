// No Copyright.

#include "Data/AuraInputConfig.h"

UInputAction* UAuraInputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FAuraInputActionConfig& InputActionConfig : NativeInputActions)
	{
		if (InputActionConfig.IsValid() && InputActionConfig.InputTag.MatchesTagExact(InInputTag))
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}

UInputAction* UAuraInputConfig::FindAbilityInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FAuraInputActionConfig& InputActionConfig : AbilityInputActions)
	{
		if (InputActionConfig.IsValid() && InputActionConfig.InputTag.MatchesTagExact(InInputTag))
		{
			return InputActionConfig.InputAction;
		}
	}
	return nullptr;
}
