// No Copyright.

#pragma once

#include "NativeGameplayTags.h"

namespace AuraGameplayTags
{
	/** Input Tags */
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Input_Move);
	
	/** Vital Attribute Tags */
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attribute_Vital_Health);
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attribute_Vital_MaxHealth);
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attribute_Vital_Mana);
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Attribute_Vital_MaxMana);
	
	/** Message Tags */
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Potion_Health);
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Potion_Mana);
	AURA_API UE_DECLARE_GAMEPLAY_TAG_EXTERN(Message_Crystal_Health);
}
