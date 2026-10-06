// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UAuraInputConfig;
class IAuraEnemyInterface;
struct FInputActionValue;

UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AAuraPlayerController();
	
	virtual void PlayerTick(float DeltaTime) override;
	
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|DataAsset")
	TObjectPtr<UAuraInputConfig> AuraInputConfig;
	
private:
	void Move(const FInputActionValue& InputActionValue);
	
	void TraceUnderCursor();
	
	FHitResult CursorHitResult;
	
	UPROPERTY(Transient)
	TScriptInterface<IAuraEnemyInterface> LastHitResultActor;
	
	UPROPERTY(Transient)
	TScriptInterface<IAuraEnemyInterface> ThisHitResultActor;
};
