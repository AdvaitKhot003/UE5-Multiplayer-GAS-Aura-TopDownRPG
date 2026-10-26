// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "AuraAttributeInfoConfig.generated.h"

USTRUCT(BlueprintType)
struct FAuraAttributeInfo
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, meta = (Categories = "Attribute"))
	FGameplayTag AttributeTag = FGameplayTag();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeName = FText();
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	FText AttributeDescription = FText();
	
	UPROPERTY(BlueprintReadOnly)
	float AttributeValue = 0.f;
	
	bool IsValid() const
	{
		return AttributeTag.IsValid() && !AttributeName.IsEmpty() && !AttributeDescription.IsEmpty();
	}
};

UCLASS()
class AURA_API UAuraAttributeInfoConfig : public UDataAsset
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Attributes", meta = (TitleProperty = "AttributeName"))
	TArray<FAuraAttributeInfo> AttributeInfoConfigs;
	
	FAuraAttributeInfo FindAttributeInfoByTag(const FGameplayTag& InAttributeTag) const;
};
