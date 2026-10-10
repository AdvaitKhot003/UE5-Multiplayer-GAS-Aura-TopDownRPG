// No Copyright.

#include "UI/HUD/AuraHUD.h"
#include "Blueprint/UserWidget.h"
#include "UI/Controller/OverlayWidgetController.h"
#include "UI/Widget/AuraUserWidget.h"

UOverlayWidgetController* AAuraHUD::GetOverlayWidgetController(const FWidgetControllerParams& Params)
{
	if (!OverlayWidgetController)
	{
		if (!OverlayWidgetControllerClass) return nullptr;
		OverlayWidgetController = NewObject<UOverlayWidgetController>(this, OverlayWidgetControllerClass);
		OverlayWidgetController->SetWidgetControllerParams(Params);
	}
	return OverlayWidgetController;
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
	OverlayWidget->AddToViewport();
}
