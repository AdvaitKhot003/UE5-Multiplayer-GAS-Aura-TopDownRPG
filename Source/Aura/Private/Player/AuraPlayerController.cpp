// No Copyright.

#include "Player/AuraPlayerController.h"
#include "Data/AuraInputConfig.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInput/AuraEnhancedInputComponent.h"
#include "GameplayTags/AuraGameplayTags.h"

AAuraPlayerController::AAuraPlayerController()
{
	SetReplicates(true);
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	if (!AuraInputConfig) return;
	
	if (!IsLocalController()) return;
	
	const ULocalPlayer* LocalPlayer = GetLocalPlayer();
	if (!IsValid(LocalPlayer)) return;
	
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	if (!IsValid(Subsystem)) return;
	
	for (const UInputMappingContext* InputMappingContext : AuraInputConfig->InputMappingContexts)
	{
		if (!InputMappingContext) continue;
		Subsystem->AddMappingContext(InputMappingContext, 0);
	}
	
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetHideCursorDuringCapture(false);
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	if (!AuraInputConfig) return;
	
	UAuraEnhancedInputComponent* AuraEnhancedInputComponent = CastChecked<UAuraEnhancedInputComponent>(InputComponent);
	
	AuraEnhancedInputComponent->BindNativeInputAction(AuraInputConfig,
		AuraGameplayTags::Input_Move, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
	
	AuraEnhancedInputComponent->BindAbilityInputAction(AuraInputConfig,
		this, &ThisClass::AbilityInputPressed, &ThisClass::AbilityInputHeld, &ThisClass::AbilityInputReleased);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	
	APawn* ControlledPawn = GetPawn<APawn>();
	if (!ControlledPawn) return;
	
	if (!FMath::IsNearlyZero(InputAxisVector.Y))
	{
		const FVector ForwardDirection = YawRotation.RotateVector(FVector::ForwardVector);
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
	}
	
	if (!FMath::IsNearlyZero(InputAxisVector.X))
	{
		const FVector RightDirection = YawRotation.RotateVector(FVector::RightVector);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAuraPlayerController::AbilityInputPressed(FGameplayTag InInputTag)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(1, 2.f, FColor::Green,
			FString::Printf(TEXT("Ability Input Pressed: %s"), *InInputTag.ToString()));
	}
}

void AAuraPlayerController::AbilityInputHeld(FGameplayTag InInputTag)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(2, 0.1f, FColor::Yellow,
			FString::Printf(TEXT("Ability Input Held: %s"), *InInputTag.ToString()));
	}
}

void AAuraPlayerController::AbilityInputReleased(FGameplayTag InInputTag)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(3, 2.f, FColor::Red,
			FString::Printf(TEXT("Ability Input Released: %s"), *InInputTag.ToString()));
	}
}
