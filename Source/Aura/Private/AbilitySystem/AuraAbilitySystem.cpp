// No Copyright.

#include "AbilitySystem/AuraAbilitySystem.h"

void UAuraAbilitySystem::OnAbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &ThisClass::ClientOnGameplayEffectApplied);
}

void UAuraAbilitySystem::ClientOnGameplayEffectApplied_Implementation(UAbilitySystemComponent* AbilitySystemComponent,
	const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer AssetTags;
	EffectSpec.GetAllAssetTags(AssetTags);
	GameplayEffectAssetTagDelegate.Broadcast(AssetTags);
}
