// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Engine/DataAsset.h"
#include "DA_InputDataAsset.generated.h"

//原生Action+Tag
USTRUCT(BlueprintType)
struct FDA_InputAction
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly)
	const class UInputAction* InputAction = nullptr;

	UPROPERTY(EditDefaultsOnly)
	FGameplayTag InputTag = FGameplayTag();
};

/**
 * 专门用于激活技能的数据资产,包含输入Action和技能Tag
 */
UCLASS()
class DRIFTARTIST_API UDA_InputDataAsset : public UDataAsset
{
	GENERATED_BODY()

public:
	//通过Tag获取 Action
	UFUNCTION(BlueprintPure)
	const UInputAction* GetInputActionFromTag(const FGameplayTag& InputTag) const;

	//通过Action获取 Tag
	UFUNCTION(BlueprintPure)
	FGameplayTag GetInputTagFromAction(const UInputAction* InputAction) const;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TArray<FDA_InputAction> AbilityInputActions;
};
