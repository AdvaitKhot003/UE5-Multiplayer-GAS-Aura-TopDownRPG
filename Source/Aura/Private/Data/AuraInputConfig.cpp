// No Copyright.

#include "Data/AuraInputConfig.h"

UInputAction* UAuraInputConfig::FindNativeInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FAuraInputActionConfig& Config : NativeInputActionConfigs)
	{
		if (Config.IsValid() && Config.InputTag.MatchesTagExact(InInputTag))
		{
			return Config.InputAction;
		}
	}
	return nullptr;
}

UInputAction* UAuraInputConfig::FindAbilityInputActionByTag(const FGameplayTag& InInputTag) const
{
	for (const FAuraInputActionConfig& Config : AbilityInputActionConfigs)
	{
		if (Config.IsValid() && Config.InputTag.MatchesTagExact(InInputTag))
		{
			return Config.InputAction;
		}
	}
	return nullptr;
}
