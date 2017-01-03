// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank found"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank is: %s"), *(ControlledTank->GetName()));
	}
}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}


