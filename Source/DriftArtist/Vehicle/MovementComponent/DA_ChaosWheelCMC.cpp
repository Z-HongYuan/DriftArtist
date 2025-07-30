// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_ChaosWheelCMC.h"


UDA_ChaosWheelCMC::UDA_ChaosWheelCMC()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UDA_ChaosWheelCMC::BeginPlay()
{
	Super::BeginPlay();
}


void UDA_ChaosWheelCMC::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
