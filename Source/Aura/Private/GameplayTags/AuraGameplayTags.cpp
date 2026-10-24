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
	
	/** Primary Attribute Tags */
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Primary_Strength,
		"Attribute.Primary.Strength",
		"Attribute tag for character strength, which increases physical damage."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Primary_Intelligence,
		"Attribute.Primary.Intelligence",
		"Attribute tag for character intelligence, which increases magical damage."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Primary_Resilience,
		"Attribute.Primary.Resilience",
		"Attribute tag for character resilience, which increases Armor and Armor Penetration."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Primary_Vigor,
		"Attribute.Primary.Vigor",
		"Attribute tag for character vigor, which increases Health."
	);
	
	/** Secondary Attribute Tags */
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_Armor,
		"Attribute.Secondary.Armor",
		"Attribute tag for Armor, which Reduces damage taken and improves Block Chance."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_ArmorPenetration,
		"Attribute.Secondary.ArmorPenetration",
		"Attribute tag for Armor Penetration, which Ignores percentage of enemy Armor and increases Crit Hit Chance."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_BlockChance,
		"Attribute.Secondary.BlockChance",
		"Attribute tag for Block Chance, which determines the chance to reduce incoming damage by half."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_CriticalHitChance,
		"Attribute.Secondary.CriticalHitChance",
		"Attribute tag for Critical Hit Chance, which determines the Chance to double damage plus critical hit bonus."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_CriticalHitDamage,
		"Attribute.Secondary.CriticalHitDamage",
		"Attribute tag for Critical Hit Damage, which determines the bonus damage added when a critical hit is scored."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_CriticalHitResistance,
		"Attribute.Secondary.CriticalHitResistance",
		"Attribute tag for Critical Hit Resistance, which reduces the Critical Hit Chance of attacking enemies."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_HealthRegeneration,
		"Attribute.Secondary.HealthRegeneration",
		"Attribute tag for Health Regeneration, which determines the amount of Health regenerated every second."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_ManaRegeneration,
		"Attribute.Secondary.ManaRegeneration",
		"Attribute tag for Mana Regeneration, which determines the amount of Mana regenerated every second."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_MaxHealth,
		"Attribute.Secondary.MaxHealth",
		"Attribute tag for Max Health, which determines the maximum amount of Health obtainable."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Secondary_MaxMana,
		"Attribute.Secondary.MaxMana",
		"Attribute tag for Max Mana, which determines the maximum amount of Mana obtainable."
	);
	
	/** Vital Attribute Tags */
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Vital_Health,
		"Attribute.Vital.Health",
		"Attribute tag for current health of the character."
	);
	
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(
		Attribute_Vital_Mana,
		"Attribute.Vital.Mana",
		"Attribute tag for current mana of the character."
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
