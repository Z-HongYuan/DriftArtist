// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AdvancedFriendsGameInstance.h"
#include "DA_GameInstance.generated.h"

/**
 * 用于保存改装数据的GameInstance
 * 持久类
 * 需要通过SaveGame进行数据处理
 */
UCLASS()
class DRIFTARTIST_API UDA_GameInstance : public UAdvancedFriendsGameInstance
{
	GENERATED_BODY()

public:
};
