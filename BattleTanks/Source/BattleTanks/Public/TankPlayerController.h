// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

// forward declaration
class ATank;


UCLASS()
class BATTLETANKS_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	ATank* ControlledTank = nullptr;

	UPROPERTY(EditDefaultsOnly)
		float CrosshairLocationX = 0.5f;
	UPROPERTY(EditDefaultsOnly)
		float CrosshairLocationY = 0.33333f;

	UPROPERTY(EditAnywhere)
		float LineTraceRange = 1000000.0f; // 10 kms

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	ATank* GetControllerTank() const;	

	// Start tank moving turret and barrel so that shot would hit
	// where the crosshair intersects the world.
	void AimTowardsCrosshair(); 

	bool GetSightRayHitLocation(FVector& Hitlocation) const;
	bool GetLookDirection(const FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const;
};
