// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "DA_PlayerControllerBase.generated.h"

/**
 * 更改的默认的摄像机管理器
 */
UCLASS()
class DRIFTARTIST_API ADA_PlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	ADA_PlayerControllerBase();
};
