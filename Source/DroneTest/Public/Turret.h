// Test assimenght for job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Turret.generated.h"

class AProjectile;

UCLASS()
class DRONETEST_API ATurret : public APawn
{
	GENERATED_BODY()

public:
	ATurret();

	virtual void Tick(float DeltaTime) override;
	void HandleDestruction();

protected:

	virtual void BeginPlay() override;

	//Behavior of turret
	void RotateTurret(FVector LookAtTarget);
	void Fire();
	
private:	
	
	//Parts of the turret
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UCapsuleComponent* CapsuleComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* BaseMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* TurretMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class USoundBase* DeathSound;

	//Stats of turret
	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	float FireRange = 300.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float TurnRate = 40.f;

	FTimerHandle FireRateTimerHandle;
	float FireRate = 2.f;

	void CheckFireCondition();

	bool InFireRange();

	class ADroneCharacter* Drone;
};
