// Test assimenght for job.


#include "DroneCharacter.h"
#include "Camera/CameraComponent.h"
#include "Projectile.h"

// Sets default values
ADroneCharacter::ADroneCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(GetMesh());

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(GetMesh());

}

// Called when the game starts or when spawned
void ADroneCharacter::BeginPlay()
{
	Super::BeginPlay();

	CurrentAmmo = MaxAmmo;
}

void ADroneCharacter::FirePoint()
{
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

	AProjectile* Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileClass, Location, Rotation);
	Projectile->SetOwner(this);
}

bool ADroneCharacter::CanFire()
{
	if (CurrentAmmo > 0)
	{
		--CurrentAmmo;
		return true;
	}
	else
		return false;
}

void ADroneCharacter::AddAmmo()
{
	CurrentAmmo = MaxAmmo;
}

float ADroneCharacter::GetAmmo() const
{
	return CurrentAmmo;
}

void ADroneCharacter::SetAmmo(float Ammo)
{
	CurrentAmmo = Ammo;
}

// Called every frame
void ADroneCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADroneCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

