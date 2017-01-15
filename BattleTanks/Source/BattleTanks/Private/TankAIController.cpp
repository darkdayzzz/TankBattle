// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("AI Controller Begin Play"));
	auto ControlledTank = GetControllerTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank found! Ensure there is an actor of class ATankAIController in the world."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AI Controlled Tank is: %s"), *(ControlledTank->GetName()));
	}
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Tank cannot find Player Tank! Ensure there is an actor of class ATankPlayerController in the world."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player Tank found and is: %s"), *(PlayerTank->GetName()));
	}
}

ATank* ATankAIController::GetControllerTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (PlayerPawn) 
	{
		return Cast<ATank>(PlayerPawn);
	}
	else
	{
		return nullptr;
	}
}


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = GetPlayerTank();
	if (PlayerTank)
	{
		AimTowardsPlayer(*PlayerTank);
	}
}

void ATankAIController::AimTowardsPlayer(const ATank& PlayerTank)
{
	auto ControlledTank = GetControllerTank();
	if (!ControlledTank) { return; }
	FVector HitLocation; // out parameter
	ControlledTank->AimAt(PlayerTank.GetActorLocation());
}
