// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "Tank.h"
#include "TankPlayerController.h"
#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("No AI Tank found! Ensure there is an actor of class ATankAIController in the world."));
	}
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AI Tank cannot find Player Tank! Ensure there is an actor of class ATankPlayerController in the world."));
	}
}


void ATankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (!ControlledTank) { return; }
	if (PlayerTank)
	{
		// TODO move towards player
		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// TODO limit firing rate
		ControlledTank->Fire();
	}
}
