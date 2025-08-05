// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DA_ColorDataAsset.generated.h"

//颜色与Tag对应
USTRUCT(BlueprintType)
struct FDA_ColorTagData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FGameplayTag Tag = FGameplayTag();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor Color;
};

/**
 * 用于颜色与Tag对应
 */
UCLASS(BlueprintType)
class DRIFTARTIST_API UDA_ColorDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure)
	FLinearColor GetColorFromTag(const FGameplayTag& InTag) const;

	UFUNCTION(BlueprintPure)
	FGameplayTag GetTagFromColor(const FLinearColor& InColor) const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FDA_ColorTagData> ColorWithTag;
};
