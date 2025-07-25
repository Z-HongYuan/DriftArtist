// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_EnhanceInputComponent.h"


UDA_EnhanceInputComponent::UDA_EnhanceInputComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}


void UDA_EnhanceInputComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UDA_EnhanceInputComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
