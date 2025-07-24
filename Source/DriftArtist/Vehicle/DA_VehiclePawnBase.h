// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
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
};
