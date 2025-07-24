// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "ChaosWheeledVehicleMovementComponent.h"
#include "SmoothSync.h"
#include "WheeledVehiclePawn.h"
#include "DriftArtist/AbilitySystem/DA_AbilitySystemComponent.h"
#include "DriftArtist/AbilitySystem/Attribute/DA_AttributeSetBase.h"
#include "GameFramework/GameplayCameraComponent.h"
#include "DA_VehiclePawnBase.generated.h"

/**
 * 添加GAS系统的载具,拥有技能释放功能,可以直接用于车辆,也可以继承后添加修改功能
 */
UCLASS()
class DRIFTARTIST_API ADA_VehiclePawnBase : public AWheeledVehiclePawn, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ADA_VehiclePawnBase();

	/*
	 * 使用缓存CMC返回增强型CMC组件,官方组件解释默认CMC是UChaosWheeledVehicleMovementComponent,但是从蓝图中获取是基础CMC组件,拓展性不高
	 * 按照默认配置,返回增强CMC组件应该没有问题
	 */
	UFUNCTION(BlueprintPure, Category = "Vehicle|Movement", meta = (DisplayName = "Get Vehicle CMC"))
	UChaosWheeledVehicleMovementComponent* GetVehicleCMC() const
	{
		return CacheCMC == nullptr ? CacheCMC = Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent()) : CacheCMC;
		// return Cast<UChaosWheeledVehicleMovementComponent>(GetVehicleMovementComponent());
	}


	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_Controller() override;

	//交给谁初始化?
	virtual UDA_AbilitySystemComponent* GetAbilitySystemComponent() const override { return AbilitySystemComponent; }
	UDA_AttributeSetBase* GetAttributeSet() const { return AttributeSet; }

	//用于初始化技能系统,可能包含属性初始化
	UFUNCTION(BlueprintCallable)
	void InitAbilitySystem();

	void InitStartAbilitiesAndEffects();

protected:
	/*
	 * 摄像机系统
	 * 没有需要自定义的地方,直接使用蓝图设置即可
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UGameplayCameraComponent> GameplayCamera;

	/*
	 * 技能系统
	 * 
	 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UDA_AbilitySystemComponent> AbilitySystemComponent;
	UPROPERTY()
	TObjectPtr<UDA_AttributeSetBase> AttributeSet;

	//默认属性GE
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TSubclassOf<UGameplayEffect> DefaultAttributeSet;

	//初始GE
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayEffect>> StartupEffects;

	//初始技能
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayAbility>> StartupAbilities;

	//初始执行一次技能
	UPROPERTY(EditDefaultsOnly, Category = "AbilitySystem")
	TArray<TSubclassOf<UGameplayAbility>> StartupDoOnceAbilities;

private:
	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<USmoothSync> SmoothSync;

	UPROPERTY()
	mutable TObjectPtr<UChaosWheeledVehicleMovementComponent> CacheCMC;
};
