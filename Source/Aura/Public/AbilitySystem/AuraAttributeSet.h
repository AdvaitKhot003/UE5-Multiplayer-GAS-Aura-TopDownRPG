// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

USTRUCT(BlueprintType)
struct FEffectProperties
{
	GENERATED_BODY()
	
	FGameplayEffectContextHandle EffectContextHandle;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> SourceAbilitySystem = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> SourceAvatarActor = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AController> SourceController = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACharacter> SourceCharacter = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<UAbilitySystemComponent> TargetAbilitySystem = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AActor> TargetAvatarActor = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<AController> TargetController = nullptr;
	
	UPROPERTY(BlueprintReadOnly)
	TObjectPtr<ACharacter> TargetCharacter = nullptr;
};

UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
	
public:
	UAuraAttributeSet();
	
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Aura|Attributes|Primary")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS_BASIC(UAuraAttributeSet, Health);
	
	UFUNCTION() void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Aura|Attributes|Primary")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS_BASIC(UAuraAttributeSet, MaxHealth);
	
	UFUNCTION() void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Aura|Attributes|Primary")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS_BASIC(UAuraAttributeSet, Mana);
	
	UFUNCTION() void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Aura|Attributes|Primary")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS_BASIC(UAuraAttributeSet, MaxMana);
	
	UFUNCTION() void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
private:
	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
};
