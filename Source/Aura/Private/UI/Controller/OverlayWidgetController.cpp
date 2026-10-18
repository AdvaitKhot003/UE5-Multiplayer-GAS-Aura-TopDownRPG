// No Copyright.

#include "UI/Controller/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "AbilitySystem/AuraAbilitySystem.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	if (!AuraAttributeSet) return;
	
	OnHealthChanged.Broadcast(AuraAttributeSet->GetHealth());
	OnMaxHealthChanged.Broadcast(AuraAttributeSet->GetMaxHealth());
	OnManaChanged.Broadcast(AuraAttributeSet->GetMana());
	OnMaxManaChanged.Broadcast(AuraAttributeSet->GetMaxMana());
}

void UOverlayWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	UAuraAbilitySystem* AuraAbilitySystem = Cast<UAuraAbilitySystem>(AbilitySystem);
	if (!AuraAttributeSet || !AuraAbilitySystem) return;
	
	AuraAbilitySystem->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetHealthAttribute()).AddUObject(this, &ThisClass::HealthChanged);
	
	AuraAbilitySystem->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxHealthAttribute()).AddUObject(this, &ThisClass::MaxHealthChanged);
	
	AuraAbilitySystem->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetManaAttribute()).AddUObject(this, &ThisClass::ManaChanged);
	
	AuraAbilitySystem->GetGameplayAttributeValueChangeDelegate(
		AuraAttributeSet->GetMaxManaAttribute()).AddUObject(this, &ThisClass::MaxManaChanged);
	
	AuraAbilitySystem->GameplayEffectAssetTagDelegate.AddUObject(this, &ThisClass::OnGameplayEffectAssetTagsReceived);
}

void UOverlayWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UOverlayWidgetController::OnGameplayEffectAssetTagsReceived(const FGameplayTagContainer& AssetTags) const
{
	if (AssetTags.IsEmpty()) return;
	
	for (const FGameplayTag& AssetTag : AssetTags)
	{
		if (!AssetTag.MatchesTag(FGameplayTag::RequestGameplayTag(TEXT("Message")))) continue;
		if (const FUIMessageWidgetRow* Row = FindDataTableRowByTag<FUIMessageWidgetRow>(MessageWidgetData, AssetTag))
		{
			UIMessageWidgetRowDelegate.Broadcast(*Row);
		}
	}
}
