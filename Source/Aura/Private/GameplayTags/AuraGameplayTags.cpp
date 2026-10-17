// No Copyright.

#include "GameplayTags/AuraGameplayTags.h"

namespace AuraGameplayTags
{
	/** Input Tags */
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Input_Move,
		"Input.Move",
		"Input tag for player movement."
	);
	
	/* Vital Attribute Tags */
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Vital_Health,
		"Attribute.Vital.Health",
		"Attribute tag for current health of the character."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Vital_MaxHealth,
		"Attribute.Vital.MaxHealth",
		"Attribute tag for maximum health the character can have."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Vital_Mana,
		"Attribute.Vital.Mana",
		"Attribute tag for current mana of the character."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Vital_MaxMana,
		"Attribute.Vital.MaxMana",
		"Attribute tag for maximum mana the character can have."
	);
	
	/** Message Tags */
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Message_Potion_Health,
		"Message.Potion.Health",
		"Message tag used to display popup when a health potion is consumed."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Message_Potion_Mana,
		"Message.Potion.Mana",
		"Message tag used to display popup when a Mana potion is consumed."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Message_Crystal_Health,
		"Message.Crystal.Health",
		"Message tag used to display popup when a health Crystal is consumed."
	);
}
