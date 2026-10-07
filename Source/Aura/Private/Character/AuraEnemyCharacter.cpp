// No Copyright.

#include "Character/AuraEnemyCharacter.h"
#include "Aura/Aura.h"
#include "Components/CapsuleComponent.h"
#include "AbilitySystem/AuraAbilitySystem.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCapsuleComponent()->InitCapsuleSize(34, 84);
	
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
	
	AbilitySystem = CreateDefaultSubobject<UAuraAbilitySystem>(FName("AuraAbilitySystemComp"));
	AbilitySystem->SetIsReplicated(true);
	AbilitySystem->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>(FName("AuraAttributeSet"));
}

UAbilitySystemComponent* AAuraEnemyCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

UAttributeSet* AAuraEnemyCharacter::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	InitAbilityEnemyInfo();
}

void AAuraEnemyCharacter::InitAbilityEnemyInfo()
{
	AbilitySystem->InitAbilityActorInfo(this, this);
}

void AAuraEnemyCharacter::HighlightEnemy()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	
	WeaponMesh->SetRenderCustomDepth(true);
	WeaponMesh->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemyCharacter::UnhighlightEnemy()
{
	GetMesh()->SetRenderCustomDepth(false);
	WeaponMesh->SetRenderCustomDepth(false);
}
