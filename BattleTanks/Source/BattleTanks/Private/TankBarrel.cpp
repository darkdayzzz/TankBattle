// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTanks.h"
#include "TankBarrel.h"

void UTankBarrel::Elevate(float DegreesPerSecond)
{
	UE_LOG(LogTemp, Warning, TEXT("Barrel elevate at speed %f"), DegreesPerSecond);
}


