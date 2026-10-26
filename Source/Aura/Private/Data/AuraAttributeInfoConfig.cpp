// No Copyright.

#include "Data/AuraAttributeInfoConfig.h"

FAuraAttributeInfo UAuraAttributeInfoConfig::FindAttributeInfoByTag(const FGameplayTag& InAttributeTag) const
{
	for (const FAuraAttributeInfo& Config : AttributeInfoConfigs)
	{
		if (Config.IsValid() && Config.AttributeTag.MatchesTagExact(InAttributeTag))
		{
			return Config;
		}
	}
	return FAuraAttributeInfo();
}
