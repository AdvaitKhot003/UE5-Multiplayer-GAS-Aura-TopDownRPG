// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "AuraCharacterBase.h"
#include "AuraPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerCharacter : public AAuraCharacterBase
{
	GENERATED_BODY()
	
public:
	AAuraPlayerCharacter();
	
protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Aura|Camera")
	TObjectPtr<USpringArmComponent> CameraBoom;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Aura|Camera")
	TObjectPtr<UCameraComponent> FollowCamera;
};
