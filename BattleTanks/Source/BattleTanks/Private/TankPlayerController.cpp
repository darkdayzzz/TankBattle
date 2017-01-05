// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	ControlledTank = GetControllerTank();
	if (!ControlledTank) 
	{
		UE_LOG(LogTemp, Error, TEXT("No Tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Controlled Tank is: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankPlayerController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


void ATankPlayerController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	AimTowardsCrosshair();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ControlledTank) { return; }
	FVector HitLocation; // out parameter
	if (GetSightRayHitLocation(HitLocation))
	{
		/// TODO Tell controller tank to aim at this point
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& Hitlocation) const
{
	bool bHittingSomething = false;
	int32 ViewportSizeX;
	int32 ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation(ViewportSizeX * CrosshairLocationX + 2.5, ViewportSizeY * CrosshairLocationY + 2.5);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Look Direction: %s"), *(LookDirection.ToString()));
		/// get vector from camera to aiming reticle 
		/// ray-cast along vector to find where ray-trace intersects first object hit by ray-trace (up to max range)
		/// if we hit something
			/// assign world-coordinates at intersection of hit to HitLocation
			/// return function is true	
	};

	return bHittingSomething;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X,
		ScreenLocation.Y,
		CameraLocation,
		LookDirection
	);
}