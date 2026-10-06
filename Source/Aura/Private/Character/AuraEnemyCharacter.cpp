// No Copyright.

#include "Character/AuraEnemyCharacter.h"
#include "Components/CapsuleComponent.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetCapsuleComponent()->InitCapsuleSize(34, 84);
}
