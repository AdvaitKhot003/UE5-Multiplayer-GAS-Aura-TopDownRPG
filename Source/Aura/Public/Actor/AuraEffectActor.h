// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "ActiveGameplayEffectHandle.h"
#include "GameFramework/Actor.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;
class UAbilitySystemComponent;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy : uint8
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy : uint8
{
	RemoveOnEndOverlap,
	DoNotRemove
};

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:
	AAuraEffectActor();
	
protected:
	UFUNCTION(BlueprintCallable)
	void OnBeginOverlap(AActor* TargetActor);
	
	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Aura|Effects")
	TObjectPtr<USceneComponent> EffectRoot;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects")
	float EffectLevel = 1.f;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects")
	bool bDestroyOnOverlap = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects")
	bool bDestroyOnEndOverlap = false;
	
#pragma region Instant Gameplay Effect
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|InstantEffect")
	EEffectApplicationPolicy InstantApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|InstantEffect")
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
#pragma endregion
	
#pragma region Duration Gameplay Effect
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|DurationEffect")
	EEffectApplicationPolicy DurationApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|DurationEffect")
	TSubclassOf<UGameplayEffect> DurationGameplayEffectClass;
#pragma endregion
	
#pragma region Infinite Gameplay Effect
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|InfiniteEffect")
	EEffectApplicationPolicy InfiniteApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|InfiniteEffect")
	EEffectRemovalPolicy InfiniteRemovalPolicy = EEffectRemovalPolicy::DoNotRemove;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|InfiniteEffect")
	TSubclassOf<UGameplayEffect> InfiniteGameplayEffectClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|Effects|InfiniteEffect")
	int32 StacksToRemove = -1;
#pragma endregion
	
private:
	void ApplyEffectToTarget(AActor* TargetActor, const TSubclassOf<UGameplayEffect> GameplayEffectClass);
	void RemoveActiveEffectsFromTarget(AActor* TargetActor);
	
	UPROPERTY(Transient)
	TMap<FActiveGameplayEffectHandle, TObjectPtr<UAbilitySystemComponent>> ActiveEffectHandles;
};
