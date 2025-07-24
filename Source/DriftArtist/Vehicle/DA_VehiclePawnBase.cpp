// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_VehiclePawnBase.h"

ADA_VehiclePawnBase::ADA_VehiclePawnBase()
{
	
	GameplayCamera = CreateDefaultSubobject<UGameplayCameraComponent>(TEXT("GameplayCameraComponent"));
	GameplayCamera->SetupAttachment(GetMesh());

	GetMesh()->SetSimulatePhysics(true);
}
