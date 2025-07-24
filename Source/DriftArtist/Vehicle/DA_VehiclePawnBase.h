// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WheeledVehiclePawn.h"
#include "GameFramework/GameplayCameraComponent.h"
#include "DA_VehiclePawnBase.generated.h"

/**
 * 添加GAS系统的载具,拥有技能释放功能,可以直接用于车辆,也可以继承后添加修改功能
 */
UCLASS()
class DRIFTARTIST_API ADA_VehiclePawnBase : public AWheeledVehiclePawn
{
	GENERATED_BODY()

public:
	ADA_VehiclePawnBase();

protected:
	//摄像机系统
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UGameplayCameraComponent> GameplayCamera;

private:
};
