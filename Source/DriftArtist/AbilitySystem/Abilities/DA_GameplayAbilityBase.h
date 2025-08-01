// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "DA_GameplayAbilityBase.generated.h"

/**
 * AbilityBase
 * 采用输入tag进行判断
 * 按键释放时会触发OnInputReleased(本地判断)
 */
UCLASS()
class DRIFTARTIST_API UDA_GameplayAbilityBase : public UGameplayAbility
{
	GENERATED_BODY()

public:
	UDA_GameplayAbilityBase();

	//InputTag,用于判断输入
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "0_InputTag")
	FGameplayTag InputTag = FGameplayTag();

	//判定是否需要Held中每帧触发
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "0_InputTag")
	bool bIsNeedHeld = false;

	//输入释放操作,从ASC触发
	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "OnInputReleased"), Category = "Ability")
	void K2_OnInputReleased();

	//技能图标材质
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Icon")
	TObjectPtr<UMaterialInterface> AbilityIconMaterial;

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                             const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                        const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility, bool bWasCancelled) override;

	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                          const FGameplayAbilityActivationInfo ActivationInfo) override;

	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
	                           const FGameplayAbilityActivationInfo ActivationInfo) override;
};
