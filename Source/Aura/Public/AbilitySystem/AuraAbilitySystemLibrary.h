// No Copyright.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AuraAbilitySystemLibrary.generated.h"

class UOverlayWidgetController;
class UAttributeMenuWidgetController;

UCLASS()
class AURA_API UAuraAbilitySystemLibrary : public UAbilitySystemBlueprintLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintPure, Category = "Aura|AbilitySystemLibrary|WidgetController", meta = (WorldContext = "WorldContextObject"))
	static UOverlayWidgetController* GetOverlayWidgetController(UObject* WorldContextObject);
	
	UFUNCTION(BlueprintPure, Category = "Aura|AbilitySystemLibrary|WidgetController", meta = (WorldContext = "WorldContextObject"))
	static UAttributeMenuWidgetController* GetAttributeMenuWidgetController(UObject* WorldContextObject);
};
