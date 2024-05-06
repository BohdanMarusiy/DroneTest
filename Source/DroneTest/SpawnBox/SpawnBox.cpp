// Test assimenght for job.


#include "SpawnBox.h"
#include "Components/StaticMeshComponent.h"
#include "DroneCharacter.h"

// Sets default values
ASpawnBox::ASpawnBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BoxMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BoxMesh"));
	RootComponent = BoxMesh;

	BoxMesh->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	BoxMesh->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	BoxMesh->OnComponentBeginOverlap.AddDynamic(this, &ASpawnBox::OnOverlap);
}

// Called when the game starts or when spawned
void ASpawnBox::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASpawnBox::OnOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if (OtherActor && OtherActor != this)
	{
		if (OtherActor->IsA<ADroneCharacter>())
		{
			ADroneCharacter* Drone = Cast<ADroneCharacter>(OtherActor);
			if (Drone)
			{
				CollectBox();
				Destroy();
			}
		}
	}
}

void ASpawnBox::CollectBox()
{
}

// Called every frame
void ASpawnBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

