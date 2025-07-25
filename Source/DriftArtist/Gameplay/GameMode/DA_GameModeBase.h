// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DA_GameModeBase.generated.h"

/**
 * 启动无缝漫游的游戏模式
 */
UCLASS()
class DRIFTARTIST_API ADA_GameModeBase : public AGameMode
{
	GENERATED_BODY()

public:
	ADA_GameModeBase();
};
