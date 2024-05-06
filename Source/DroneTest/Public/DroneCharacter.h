// Test assimenght for job.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "DroneCharacter.generated.h"


class AProjectile;

UCLASS()
class DRONETEST_API ADroneCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ADroneCharacter();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	bool bAlive = true;

	void FirePoint();
	
	bool CanFire();

	void AddAmmo();

	UFUNCTION(BlueprintCallable, Category = "Combat")
	float GetAmmo() const;

	UFUNCTION(BlueprintCallable, Category = "Combat")
	void SetAmmo(float Ammo);
protected:

	virtual void BeginPlay() override;
	
private:

	UPROPERTY(VisibleAnywhere, Category = "Components")
	class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere, Category = "Components", meta = (AllowPrivateAccess = "true"))
	USceneComponent* ProjectileSpawnPoint;

	UPROPERTY(EditDefaultsOnly, Category = "Combat")
	TSubclassOf<AProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Combat")
	float MaxAmmo = 30.f;

	float CurrentAmmo;
	
};
