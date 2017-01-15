// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANKS_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max upward speed
	void Elevate(float RelativeSpeed);
	
private:
	// maximum speed in degrees per second to raise/lower barrel
	UPROPERTY(EditAnywhere, Category=Setup)
		float MaxDegreesPerSecond = 10.0f; 

	// minimum elevation in degrees for barrel
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationInDegrees = 0.0f; 

	// maximum elevation in degrees for barrel
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationInDegrees = 35.0f; 

};
