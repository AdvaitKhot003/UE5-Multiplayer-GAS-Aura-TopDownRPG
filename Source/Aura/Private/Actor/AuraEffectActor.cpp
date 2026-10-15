// No Copyright.

#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	EffectRoot = CreateDefaultSubobject<USceneComponent>("SceneComp");
	SetRootComponent(EffectRoot);
}

void AAuraEffectActor::OnBeginOverlap(AActor* TargetActor)
{
	if (InstantApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	
	if (DurationApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	
	if (InfiniteApplicationPolicy == EEffectApplicationPolicy::ApplyOnOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	
	if (bDestroyOnOverlap == true)
	{
		Destroy();
	}
}

void AAuraEffectActor::OnEndOverlap(AActor* TargetActor)
{
	if (InstantApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InstantGameplayEffectClass);
	}
	
	if (DurationApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, DurationGameplayEffectClass);
	}
	
	if (InfiniteApplicationPolicy == EEffectApplicationPolicy::ApplyOnEndOverlap)
	{
		ApplyEffectToTarget(TargetActor, InfiniteGameplayEffectClass);
	}
	
	if (InfiniteRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
	{
		RemoveActiveEffectsFromTarget(TargetActor);
	}
	
	if (bDestroyOnEndOverlap == true)
	{
		Destroy();
	}
}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	if (!HasAuthority() || !TargetActor || !GameplayEffectClass) return;
	
	UAbilitySystemComponent* TargetAsc = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (!TargetAsc) return;
	
	FGameplayEffectContextHandle EffectContextHandle = TargetAsc->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	
	const FGameplayEffectSpecHandle EffectSpecHandle =
		TargetAsc->MakeOutgoingSpec(GameplayEffectClass, EffectLevel, EffectContextHandle);
	
	if (!EffectSpecHandle.IsValid()) return;
	
	const FActiveGameplayEffectHandle ActiveEffectHandle =
		TargetAsc->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
	
	if (!ActiveEffectHandle.IsValid()) return;
	
	const UGameplayEffect* GameplayEffect = EffectSpecHandle.Data.Get()->Def.Get();
	if (!GameplayEffect) return;
	
	if (GameplayEffect->DurationPolicy == EGameplayEffectDurationType::Infinite)
	{
		if (InfiniteRemovalPolicy == EEffectRemovalPolicy::RemoveOnEndOverlap)
		{
			ActiveEffectHandles.Add(ActiveEffectHandle, TargetAsc);
		}
	}
}

void AAuraEffectActor::RemoveActiveEffectsFromTarget(AActor* TargetActor)
{
	if (!HasAuthority() || !TargetActor) return;
	
	UAbilitySystemComponent* TargetAsc = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (!TargetAsc) return;
	
	TArray<FActiveGameplayEffectHandle> ActiveEffectHandlesToRemove;
	
	for (const auto& Handle : ActiveEffectHandles)
	{
		if (Handle.Value != TargetAsc) continue;
		TargetAsc->RemoveActiveGameplayEffect(Handle.Key, StacksToRemove);
		ActiveEffectHandlesToRemove.Add(Handle.Key);
	}
	
	for (const FActiveGameplayEffectHandle& HandleToRemove : ActiveEffectHandlesToRemove)
	{
		ActiveEffectHandles.FindAndRemoveChecked(HandleToRemove);
	}
}
