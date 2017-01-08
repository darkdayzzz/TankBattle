// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANKS_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	void AimAt(const FVector HitLocation, float LaunchSpeed);

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

private:
	UStaticMeshComponent* Barrel = nullptr;
	// TODO add Turret and SetTurretReference method

	// Sets default values for this component's properties
	UTankAimingComponent();
		
	void MoveBarrelTowards(FVector AimDirection);
};
