// No Copyright.

#include "AbilitySystem/AuraAbilitySystemLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Player/AuraPlayerState.h"
#include "UI/Controller/AuraWidgetController.h"
#include "UI/HUD/AuraHUD.h"

UOverlayWidgetController* UAuraAbilitySystemLibrary::GetOverlayWidgetController(UObject* WorldContextObject)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!PlayerController) return nullptr;
	
	AAuraPlayerState* AuraPlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
	if (!AuraPlayerState) return nullptr;
	
	UAbilitySystemComponent* AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return nullptr;
	
	UAttributeSet* AttributeSet = AuraPlayerState->GetAttributeSet();
	if (!AttributeSet) return nullptr;
	
	AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD());
	if (!AuraHUD) return nullptr;
	
	const FWidgetControllerParams WidgetControllerParams(
		PlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
	
	return AuraHUD->GetOverlayWidgetController(WidgetControllerParams);
}

UAttributeMenuWidgetController* UAuraAbilitySystemLibrary::GetAttributeMenuWidgetController(UObject* WorldContextObject)
{
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(WorldContextObject, 0);
	if (!PlayerController) return nullptr;
	
	AAuraPlayerState* AuraPlayerState = PlayerController->GetPlayerState<AAuraPlayerState>();
	if (!AuraPlayerState) return nullptr;
	
	UAbilitySystemComponent* AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	if (!AbilitySystemComponent) return nullptr;
	
	UAttributeSet* AttributeSet = AuraPlayerState->GetAttributeSet();
	if (!AttributeSet) return nullptr;
	
	AAuraHUD* AuraHUD = Cast<AAuraHUD>(PlayerController->GetHUD());
	if (!AuraHUD) return nullptr;
	
	const FWidgetControllerParams WidgetControllerParams(
		PlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
	
	return AuraHUD->GetAttributeMenuWidgetController(WidgetControllerParams);
}
