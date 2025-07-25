// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DriftArtist/AbilitySystem/DA_AbilitySystemComponent.h"
#include "GameFramework/PlayerController.h"
#include "DA_PlayerControllerBase.generated.h"

class UInputMappingContext;
class UDA_InputDataAsset;
/**
 * 更改的默认的摄像机管理器
 */
UCLASS()
class DRIFTARTIST_API ADA_PlayerControllerBase : public APlayerController
{
	GENERATED_BODY()

public:
	ADA_PlayerControllerBase();

	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultAbilityContext;

	//Ability与Tag对应的数据资产
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Input")
	TObjectPtr<UDA_InputDataAsset> InputDataAsset;

	//用于在ASC内触发输入的函数
	void AbilityInputTagPressed(FGameplayTag InputTag);
	void AbilityInputTagReleased(FGameplayTag InputTag);
	void AbilityInputTagHeld(FGameplayTag InputTag);

	TWeakObjectPtr<UDA_AbilitySystemComponent> AvatarASC;
	UDA_AbilitySystemComponent* GetASC();
};
