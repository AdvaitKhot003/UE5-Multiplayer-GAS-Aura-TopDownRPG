// No Copyright.

#include "UI/Controller/AttributeMenuWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Data/AuraAttributeInfoConfig.h"

void UAttributeMenuWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	if (!AuraAttributeSet || !AuraAttributeInfoConfig) return;
	
	for (auto& Pair : AuraAttributeSet->TagsToAttributes)
	{
		FAuraAttributeInfo AttributeInfo = AuraAttributeInfoConfig->FindAttributeInfoByTag(Pair.Key);
		AttributeInfo.AttributeValue = Pair.Value().GetNumericValue(AuraAttributeSet);
		AttributeInfoDelegate.Broadcast(AttributeInfo);
	}
}

void UAttributeMenuWidgetController::BindCallbacksToDependencies()
{
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	if (!AuraAttributeSet || !AbilitySystem || !AuraAttributeInfoConfig) return;
	
	for (auto& Pair : AuraAttributeSet->TagsToAttributes)
	{
		AbilitySystem->GetGameplayAttributeValueChangeDelegate(Pair.Value()).AddLambda(
			[this, AttributeTag = Pair.Key](const FOnAttributeChangeData& Data)
			{
				FAuraAttributeInfo AttributeInfo = AuraAttributeInfoConfig->FindAttributeInfoByTag(AttributeTag);
				AttributeInfo.AttributeValue = Data.NewValue;
				AttributeInfoDelegate.Broadcast(AttributeInfo);
			}
		);
	}
}
