// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_PlayerControllerBase.h"
#include "GameFramework/GameplayCamerasPlayerCameraManager.h"

ADA_PlayerControllerBase::ADA_PlayerControllerBase()
{
	PlayerCameraManagerClass = AGameplayCamerasPlayerCameraManager::StaticClass();
}
