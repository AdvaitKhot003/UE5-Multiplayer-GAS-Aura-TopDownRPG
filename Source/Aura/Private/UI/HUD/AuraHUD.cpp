// No Copyright.

#include "UI/HUD/AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "UI/Controller/AttributeMenuWidgetController.h"
#include "UI/Widget/AuraUserWidget.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (!OverlayWidgetController)
	{
		if (!OverlayWidgetControllerClass) return nullptr;
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
		OverlayWidgetController->BindCallbacksToDependencies();
	}
	return OverlayWidgetController;
}

UAttributeMenuWidgetController* AAuraHUD::GetAttributeMenuWidgetController(const FWidgetControllerParams& Params)
{
	if (!AttributeMenuWidgetController)
	{
		if (!AttributeMenuWidgetControllerClass) return nullptr;
		AttributeMenuWidgetController = NewObject<UAttributeMenuWidgetController>(this, AttributeMenuWidgetControllerClass);
		AttributeMenuWidgetController->SetWidgetControllerParams(Params);
		AttributeMenuWidgetController->BindCallbacksToDependencies();
	}
	return AttributeMenuWidgetController;
}

void AAuraHUD::InitOverlayWidget(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS)
{
	if (!OverlayWidgetClass) return;
	if (!OverlayWidgetControllerClass) return;
	
	OverlayWidget = CreateWidget<UAuraUserWidget>(PC, OverlayWidgetClass);
	if (!OverlayWidget) return;
	
	const FWidgetControllerParams WidgetControllerParams(PC, PS, ASC, AS);
	UOverlayWidgetController* WidgetController = GetOverlayWidgetController(WidgetControllerParams);
	if (!WidgetController) return;
	
	OverlayWidget->SetWidgetController(WidgetController);
	WidgetController->BroadcastInitialValues();
	
	OverlayWidget->AddToViewport();
}
