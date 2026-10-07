// No Copyright.

#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystem.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystem = CreateDefaultSubobject<UAuraAbilitySystem>(FName("AuraAbilitySystemComp"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>(FName("AuraAttributeSet"));
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}
