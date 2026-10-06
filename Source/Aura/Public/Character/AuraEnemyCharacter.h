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
	
#pragma region Enemy Interface
	virtual void HighlightEnemy() override;
	virtual void UnhighlightEnemy() override;
#pragma endregion
};
