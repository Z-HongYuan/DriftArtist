// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "DA_ChaosWheelCMC.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRIFTARTIST_API UDA_ChaosWheelCMC : public UChaosWheeledVehicleMovementComponent
{
	GENERATED_BODY()

public:
	UDA_ChaosWheelCMC();

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};
