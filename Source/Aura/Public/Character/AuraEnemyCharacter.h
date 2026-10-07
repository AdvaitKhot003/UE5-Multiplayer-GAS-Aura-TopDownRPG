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
	
#pragma region Enemy Interface
	virtual void HighlightEnemy() override;
	virtual void UnhighlightEnemy() override;
#pragma endregion
	
private:
	void InitAbilityEnemyInfo();
};
