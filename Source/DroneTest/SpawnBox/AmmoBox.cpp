// Test assimenght for job.


#include "AmmoBox.h"
#include "DroneCharacter.h"
#include "Kismet/GameplayStatics.h"


void AAmmoBox::BeginPlay()
{
	Super::BeginPlay();

	Drone = Cast<ADroneCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void AAmmoBox::CollectBox()
{
	Drone->AddAmmo();
}
