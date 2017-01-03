// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankPlayerController.h"


void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));
	auto ControlledTank = GetControllerTank();
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

