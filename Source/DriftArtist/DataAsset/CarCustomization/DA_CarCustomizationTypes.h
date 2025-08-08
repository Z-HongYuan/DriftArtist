// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DA_CarCustomizationTypes.generated.h"

UENUM(BlueprintType)
enum class EDA_CarCustomizationType : uint8
{
	Engine,
	Wheel,
	Suspension,
	Bumper,
	PaintStorageTank,
	Nozzle,
	CarCustomizationType_Max UMETA(Hidden)
};

USTRUCT(BlueprintType)
struct FDA_CarCustomizationTableRow : public FTableRowBase
{
	GENERATED_BODY()

public:
	//改装的图标
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UTexture2D* Icon;
	
	//所属车辆名字
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	FString VehicleName;

	//所属改装件类型
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	EDA_CarCustomizationType RefitModelType;

	//需要改装的性能升级Name
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "性能升级")
	FString PerformanceUpgradesName;

	//需要改变的数值
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "性能升级")
	float UpgradesNum = 0.f;

	//需要改变的Mesh
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "外观升级")
	TObjectPtr<UStaticMesh> MeshRef;
	
};

/**
 * 用于车辆定制的类型
 */
UCLASS()
class DRIFTARTIST_API UDA_CarCustomizationTypes : public UDataTable
{
	GENERATED_BODY()

public:
};
