// No Copyright.

#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/AuraEnhancedInput.h"
#include "GameplayTags/AuraGameplayTags.h"
#include "Interface/AuraEnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	SetReplicates(true);
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!AuraInputConfig || !IsLocalController()) return;
	
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!LocalPlayer) return;
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	if (!Subsystem) return;
	
	for (const UInputMappingContext* InputMappingContext : AuraInputConfig->InputMappingContexts)
	{
		if (!InputMappingContext) continue;
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	
	SetShowMouseCursor(true);
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetHideCursorDuringCapture(false);
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	
	if (!IsLocalController()) return;
	TraceUnderCursor();
}

void AAuraPlayerController::TraceUnderCursor()
{
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHitResult);
	
	LastHitResultActor = ThisHitResultActor;
	ThisHitResultActor = nullptr;
	
	if (CursorHitResult.IsValidBlockingHit()) ThisHitResultActor = CursorHitResult.GetActor();
	if (LastHitResultActor == ThisHitResultActor) return;
	
	if (LastHitResultActor) LastHitResultActor->UnhighlightEnemy();
	if (ThisHitResultActor) ThisHitResultActor->HighlightEnemy();
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (!AuraInputConfig) return;
	
	UAuraEnhancedInput* AuraEnhancedInput = CastChecked<UAuraEnhancedInput>(InputComponent);
	
	AuraEnhancedInput->BindNativeInputAction(
		AuraInputConfig, AuraGameplayTags::Input_Move, ETriggerEvent::Triggered, this, &ThisClass::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisValue = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	APawn* ControlledPawn = GetPawn<APawn>();
	if (!ControlledPawn) return;
	
	if (!FMath::IsNearlyZero(InputAxisValue.Y))
	{
		const FVector ForwardDirection = YawRotation.RotateVector(FVector::ForwardVector);
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisValue.Y);
	}
	
	if (!FMath::IsNearlyZero(InputAxisValue.X))
	{
		const FVector RightDirection = YawRotation.RotateVector(FVector::RightVector);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisValue.X);
	}
}
