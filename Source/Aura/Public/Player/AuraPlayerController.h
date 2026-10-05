// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UAuraInputConfig;
struct FInputActionValue;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAuraPlayerController();
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|DataAsset")
	TObjectPtr<UAuraInputConfig> AuraInputConfig;
	
private:
	void Move(const FInputActionValue& InputActionValue);
};
