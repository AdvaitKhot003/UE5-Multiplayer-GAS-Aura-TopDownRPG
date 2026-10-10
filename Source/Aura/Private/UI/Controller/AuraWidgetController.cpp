// No Copyright.

#include "UI/Controller/AuraWidgetController.h"

void UAuraWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& Params)
{
	PlayerController = Params.PlayerController;
	PlayerState = Params.PlayerState;
	AbilitySystem = Params.AbilitySystem;
	AttributeSet = Params.AttributeSet;
}
