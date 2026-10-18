// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "AuraWidgetController.h"
#include "AbilitySystemComponent.h"
#include "OverlayWidgetController.generated.h"

class UAuraUserWidget;

USTRUCT(BlueprintType)
struct FUIMessageWidgetRow : public FTableRowBase
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|MessageWidget")
	FGameplayTag MessageTag = FGameplayTag();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|MessageWidget")
	FText MessageText = FText();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|MessageWidget")
	TSubclassOf<UAuraUserWidget> MessageWidget = nullptr;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|MessageWidget")
	UTexture2D* MessageIcon = nullptr;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeChangedSignature, float, NewValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUIMessageWidgetRowSignature, FUIMessageWidgetRow, Row);

UCLASS()
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()
	
public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;
	
	UPROPERTY(BlueprintAssignable, Category = "Aura|Attributes")
	FOnAttributeChangedSignature OnHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "Aura|Attributes")
	FOnAttributeChangedSignature OnMaxHealthChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "Aura|Attributes")
	FOnAttributeChangedSignature OnManaChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "Aura|Attributes")
	FOnAttributeChangedSignature OnMaxManaChanged;
	
	UPROPERTY(BlueprintAssignable, Category = "Aura|MessageWidget")
	FUIMessageWidgetRowSignature UIMessageWidgetRowDelegate;
	
protected:
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
	
	void OnGameplayEffectAssetTagsReceived(const FGameplayTagContainer& AssetTags) const;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|MessageWidget")
	TObjectPtr<UDataTable> MessageWidgetData;
	
	template <typename T>
	T* FindDataTableRowByTag(const UDataTable* DataTable, const FGameplayTag& InMessageTag) const;
};

template <typename T>
T* UOverlayWidgetController::FindDataTableRowByTag(const UDataTable* DataTable, const FGameplayTag& InMessageTag) const
{
	if (!DataTable) return nullptr;
	T* Row = DataTable->FindRow<T>(InMessageTag.GetTagName(), TEXT("FindDataTableRowByTag"));
	if (!Row) return nullptr;
	return Row;
}
