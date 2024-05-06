// Test assimenght for job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "DroneTestGameModeBase.generated.h"

class ADroneCharacter;
class ADronePlayerController;

UCLASS()
class DRONETEST_API ADroneTestGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:

	void ActorDied(AActor* DeadActor);

protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintImplementableEvent)
	void StartGame();

	UFUNCTION(BlueprintImplementableEvent)
	void GameOver(bool bWonGame);

private:

	ADroneCharacter* Drone;
	ADronePlayerController* DronePlayerController;

	float StartDelay = 3.f;

	void HandleGameStart();

	int32 TargetTurrets = 0;
	int32 GetTargetTurretCount();
	
};
