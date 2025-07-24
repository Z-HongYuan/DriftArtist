// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_AbilitySystemComponent.h"

#include "AbilitySystemLog.h"
#include "Abilities/DA_GameplayAbilityBase.h"


UDA_AbilitySystemComponent::UDA_AbilitySystemComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

FGameplayAbilitySpecHandle UDA_AbilitySystemComponent::GiveAbilityWithTag(FGameplayAbilitySpec& Spec)
{
	if (const UDA_GameplayAbilityBase* DA_Ability = Cast<UDA_GameplayAbilityBase>(Spec.Ability))
	{
		if (DA_Ability->InputTag.IsValid())
		{
			Spec.GetDynamicSpecSourceTags().AddTag(DA_Ability->InputTag);
		}
	}
	return GiveAbility(Spec);
}

FGameplayAbilitySpecHandle UDA_AbilitySystemComponent::K2_GiveAbilityWithTag(TSubclassOf<UGameplayAbility> AbilityClass, int32 Level, int32 InputID)
{
	// 构建并验证 Ability Spec
	FGameplayAbilitySpec AbilitySpec = BuildAbilitySpecFromClass(AbilityClass, Level, InputID);

	// 验证类
	if (!IsValid(AbilitySpec.Ability))
	{
		ABILITY_LOG(Error, TEXT("K2_GiveAbility() called with an invalid Ability Class."));

		return FGameplayAbilitySpecHandle();
	}

	// 授予 ability 并返回 handle。这将运行验证和权限检查
	return GiveAbilityWithTag(AbilitySpec);
}

void UDA_AbilitySystemComponent::AbilityInputTagPressed(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) //循环查找并激活包含有对应InputTag的Ability
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputPressed(AbilitySpec); //通知Ability内的输入按下
			if (!AbilitySpec.IsActive())
			{
				TryActivateAbility(AbilitySpec.Handle); //并且如果能力未被激活,就激活一次
			}
		}
	}
}

void UDA_AbilitySystemComponent::AbilityInputTagHeld(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) //循环查找并激活包含有对应InputTag的Ability
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			if (const UDA_GameplayAbilityBase* TwoAbility = Cast<UDA_GameplayAbilityBase>(AbilitySpec.Ability))
			{
				if (TwoAbility->bIsNeedHeld and !AbilitySpec.IsActive())
				{
					AbilitySpecInputPressed(AbilitySpec); //通知Ability内的输入按下
					TryActivateAbility(AbilitySpec.Handle); //并且如果能力未被激活,就激活一次
				}
			}
		}
	}
}

void UDA_AbilitySystemComponent::AbilityInputTagReleased(const FGameplayTag& InputTag)
{
	if (!InputTag.IsValid()) return;

	for (FGameplayAbilitySpec& AbilitySpec : GetActivatableAbilities()) //循环查找并激活包含有对应InputTag的Ability
	{
		if (AbilitySpec.GetDynamicSpecSourceTags().HasTagExact(InputTag))
		{
			AbilitySpecInputReleased(AbilitySpec); //通知Ability内的输入释放
		}
	}
}


void UDA_AbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();
}


void UDA_AbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
