// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "AuraHUD.generated.h"

class UAuraUserWidget;
class UOverlayWidgetController;
class UAttributeMenuWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;

UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& Params);
	UAttributeMenuWidgetController* GetAttributeMenuWidgetController(const FWidgetControllerParams& Params);
	
	void InitOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|HUD")
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|HUD")
	TSubclassOf<UOverlayWidgetController> OverlayWidgetControllerClass;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Aura|HUD")
	TSubclassOf<UAttributeMenuWidgetController> AttributeMenuWidgetControllerClass;
	
private:
	UPROPERTY(Transient)
	TObjectPtr<UAuraUserWidget> OverlayWidget;
	
	UPROPERTY(Transient)
	TObjectPtr<UOverlayWidgetController> OverlayWidgetController;
	
	UPROPERTY(Transient)
	TObjectPtr<UAttributeMenuWidgetController> AttributeMenuWidgetController;
};
