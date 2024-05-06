// Test assimenght for job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DronePlayerController.generated.h"



class UInputMappingContext;
class UInputAction;
struct FInputActionValue;
class ADroneCharacter;

UCLASS()
class DRONETEST_API ADronePlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
public:
	void SetPlayerEnabledState(bool bPlayerEnabled);
	

private:
	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputMappingContext> DroneContext;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> TurnAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	TObjectPtr<UInputAction> FireAction;

	UPROPERTY(EditAnywhere, Category = "Movement")
	float TurnRate = 45.f;

	ADroneCharacter* ControlledDrone;

	void Move(const FInputActionValue& InputActionValue);
	void Turn(const FInputActionValue& InputActionValue);
	void Fire(const FInputActionValue& InputActionValue);

};
