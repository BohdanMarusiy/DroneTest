// Test assimenght for job.


#include "HealthBox.h"
#include "DroneCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "../Player/HealthComponent.h"

void AHealthBox::BeginPlay()
{
	Super::BeginPlay();
	Drone = Cast<ADroneCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AHealthBox::CollectBox()
{
	UHealthComponent* HP = Cast<UHealthComponent>(Drone->GetComponentByClass(UHealthComponent::StaticClass()));
	if(HP)
	HP->Health = HP->MaxHealth;
}
