// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "Interface/AuraEnemyInterface.h"
#include "AuraEnemyCharacter.generated.h"

UCLASS()
class AURA_API AAuraEnemyCharacter : public AAuraCharacterBase, public IAuraEnemyInterface
{
	GENERATED_BODY()
	
public:
	AAuraEnemyCharacter();
	
	virtual void BeginPlay() override;
	
#pragma region Ability System Interface
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const override;
#pragma endregion
	
#pragma region Combat Interface
	virtual int32 GetCharacterLevel() const override;
#pragma endregion
	
#pragma region Enemy Interface
	virtual void HighlightEnemy() override;
	virtual void UnhighlightEnemy() override;
#pragma endregion
	
protected:
	virtual void InitAbilityCharacterInfo() override;
	
private:
	UPROPERTY(EditAnywhere, Category = "Aura|AbilitySystem")
	int32 EnemyLevel = 1;
};
