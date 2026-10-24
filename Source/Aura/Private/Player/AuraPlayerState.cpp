// No Copyright.

#include "Player/AuraPlayerState.h"
#include "AbilitySystem/AuraAbilitySystem.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Net/UnrealNetwork.h"

AAuraPlayerState::AAuraPlayerState()
{
	SetNetUpdateFrequency(100.f);
	
	AbilitySystem = CreateDefaultSubobject<UAuraAbilitySystem>(FName("AuraAbilitySystemComp"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>(FName("AuraAttributeSet"));
}

void AAuraPlayerState::GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	
	DOREPLIFETIME(AAuraPlayerState, PlayerLevel);
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

void AAuraPlayerState::OnRep_PlayerLevel(int32 OldPlayerLevel) const
{
	
}
