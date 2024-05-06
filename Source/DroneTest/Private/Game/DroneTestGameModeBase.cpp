// Test assimenght for job.


#include "Game/DroneTestGameModeBase.h"
#include "DroneCharacter.h"
#include "Turret.h"
#include "Kismet/GameplayStatics.h"
#include "../Player/DronePlayerController.h"

void ADroneTestGameModeBase::ActorDied(AActor* DeadActor)
{
    if (DeadActor == Drone)
    {
        GameOver(false);
    }
    else if (ATurret* DestroyedTurret = Cast<ATurret>(DeadActor))
    {
        DestroyedTurret->HandleDestruction();
        --TargetTurrets;
        if (TargetTurrets == 0)
        {
            GameOver(true);
        }
    }
}

void ADroneTestGameModeBase::BeginPlay()
{
    Super::BeginPlay();
    HandleGameStart();
}

void ADroneTestGameModeBase::HandleGameStart()
{
    TargetTurrets = GetTargetTurretCount();
    Drone = Cast<ADroneCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
    DronePlayerController = Cast<ADronePlayerController>(UGameplayStatics::GetPlayerController(this, 0));

    StartGame();
}

int32 ADroneTestGameModeBase::GetTargetTurretCount()
{
    TArray<AActor*> Turrets;
    UGameplayStatics::GetAllActorsOfClass(this, ATurret::StaticClass(), Turrets);
    return Turrets.Num();
}
