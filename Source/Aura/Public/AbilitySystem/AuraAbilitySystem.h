// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AuraAbilitySystem.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FGameplayEffectAssetTagDelegate, const FGameplayTagContainer&);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class AURA_API UAuraAbilitySystem : public UAbilitySystemComponent
{
	GENERATED_BODY()
	
public:
	void OnAbilityActorInfoSet();
	
	FGameplayEffectAssetTagDelegate GameplayEffectAssetTagDelegate;
	
protected:
	UFUNCTION(Client, Reliable)
	void ClientOnGameplayEffectApplied(UAbilitySystemComponent* AbilitySystemComponent,
		const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle);
};
