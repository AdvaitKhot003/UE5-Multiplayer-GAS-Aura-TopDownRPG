// No Copyright.

#include "Character/AuraCharacterBase.h"
#include "AbilitySystemComponent.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(FName("SkeletalMeshComp"));
	WeaponMesh->SetupAttachment(GetMesh(), FName("WeaponHandSocket"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::Type::NoCollision);
}

UAbilitySystemComponent* AAuraCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystem;
}

UAttributeSet* AAuraCharacterBase::GetAttributeSet() const
{
	return AttributeSet;
}

void AAuraCharacterBase::InitAbilityCharacterInfo()
{
	
}

void AAuraCharacterBase::ApplyEffectSpecToSelf(const TSubclassOf<UGameplayEffect>& GameplayEffect, float Level) const
{
	if (!HasAuthority() || !GameplayEffect) return;
	
	UAbilitySystemComponent* SourceAsc = GetAbilitySystemComponent();
	if (!SourceAsc) return;
	
	FGameplayEffectContextHandle EffectContextHandle = SourceAsc->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	
	if (!EffectContextHandle.IsValid()) return;
	
	const FGameplayEffectSpecHandle EffectSpecHandle =
		SourceAsc->MakeOutgoingSpec(GameplayEffect, Level, EffectContextHandle);
	
	if (!EffectSpecHandle.IsValid()) return;
	
	SourceAsc->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}

void AAuraCharacterBase::InitializeDefaultAttributes() const
{
	ApplyEffectSpecToSelf(PrimaryAttributes);
	ApplyEffectSpecToSelf(SecondaryAttributes);
	ApplyEffectSpecToSelf(VitalAttributes);
}
