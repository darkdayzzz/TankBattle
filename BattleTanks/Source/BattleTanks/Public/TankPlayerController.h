// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* ControlledTank = nullptr;

	UPROPERTY(EditAnywhere)
		float CrosshairLocationX = 0.5f;
	UPROPERTY(EditAnywhere)
		float CrosshairLocationY = 0.33333f;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControllerTank() const;	

	// Start tank moving turret and barrel so that shot would hit
	// where the crosshair intersects the world.
	void AimTowardsCrosshair(); 

	bool GetSightRayHitLocation(FVector& Hitlocation) const;
	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
};
