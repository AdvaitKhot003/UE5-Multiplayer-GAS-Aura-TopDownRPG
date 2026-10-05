// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AuraInputConfig.generated.h"

class UInputMappingContext;
class UInputAction;

USTRUCT(BlueprintType)
struct FAuraInputActionConfig
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Input"))
	FGameplayTag InputTag;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TObjectPtr<UInputAction> InputAction = nullptr;
	
	FORCEINLINE bool IsValid() const { return InputTag.IsValid() && InputAction != nullptr; }
};

UCLASS()
class AURA_API UAuraInputConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|EnhancedInput")
	TArray<TObjectPtr<UInputMappingContext>> InputMappingContexts;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|EnhancedInput", meta = (TitleProperty = "InputTag"))
	TArray<FAuraInputActionConfig> NativeInputActionConfigs;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|EnhancedInput", meta = (TitleProperty = "InputTag"))
	TArray<FAuraInputActionConfig> AbilityInputActionConfigs;
	
	UInputAction* FindNativeInputActionByTag(const FGameplayTag& InInputTag) const;
	UInputAction* FindAbilityInputActionByTag(const FGameplayTag& InInputTag) const;
};
