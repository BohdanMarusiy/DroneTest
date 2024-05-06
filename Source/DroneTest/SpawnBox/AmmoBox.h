// Test assimenght for job.

#pragma once

#include "CoreMinimal.h"
#include "SpawnBox.h"
#include "AmmoBox.generated.h"


class ADroneCharacter;

UCLASS()
class DRONETEST_API AAmmoBox : public ASpawnBox
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	
public:
	virtual void CollectBox() override;

private:
	ADroneCharacter* Drone;
};
