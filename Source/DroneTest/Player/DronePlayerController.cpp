// Test assimenght for job.


#include "DronePlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "DroneCharacter.h"


void ADronePlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(DroneContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);

	Subsystem->AddMappingContext(DroneContext, 0);

	ControlledDrone = Cast<ADroneCharacter>(GetPawn());


}

void ADronePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ADronePlayerController::Move);
	EnhancedInputComponent->BindAction(TurnAction, ETriggerEvent::Triggered, this, &ADronePlayerController::Turn);
	EnhancedInputComponent->BindAction(FireAction, ETriggerEvent::Triggered, this, &ADronePlayerController::Fire);
}

void ADronePlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
	}
	bShowMouseCursor = bPlayerEnabled;
}

void ADronePlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector InputAxisVector = InputActionValue.Get<FVector>();
	const FRotator Rotation = GetControlRotation();

	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	const FVector UpDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Z);

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
		ControlledPawn->AddMovementInput(UpDirection, InputAxisVector.Z);
	}

}

void ADronePlayerController::Turn(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(InputAxisVector.X);
		ControlledPawn->AddControllerPitchInput(InputAxisVector.Y);
	}

}

void ADronePlayerController::Fire(const FInputActionValue& InputActionValue)
{
	if (InputActionValue.Get<bool>())
	{
		if(ControlledDrone->CanFire())
		ControlledDrone->FirePoint();
	}
}
