// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_VehiclePawnBase.h"


ADA_VehiclePawnBase::ADA_VehiclePawnBase()
{
	//摄像机系统
	GameplayCamera = CreateDefaultSubobject<UGameplayCameraComponent>(TEXT("GameplayCameraComponent"));
	GameplayCamera->SetupAttachment(GetMesh());

	//开启模拟物理
	GetMesh()->SetSimulatePhysics(true);

	//技能系统
	AbilitySystemComponent = CreateDefaultSubobject<UDA_AbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AttributeSet = CreateDefaultSubobject<UDA_AttributeSetBase>(TEXT("AttributeSet"));

	//平滑同步
	SmoothSync = CreateDefaultSubobject<USmoothSync>(TEXT("SmoothSync"));
	SetReplicatingMovement(false);
	
}

void ADA_VehiclePawnBase::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	if (AbilitySystemComponent)
	{
		InitAbilitySystem();
	}
	SetOwner(NewController);
}

void ADA_VehiclePawnBase::OnRep_Controller()
{
	Super::OnRep_Controller();
	// if (AbilitySystemComponent)
	// {
	// 	InitAbilitySystem();
	// }
}

void ADA_VehiclePawnBase::InitAbilitySystem()
{
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	InitStartAbilitiesAndEffects();
}

void ADA_VehiclePawnBase::InitStartAbilitiesAndEffects()
{
	//初始默认属性
	if (GetAbilitySystemComponent() and DefaultAttributeSet)
	{
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(
			*GetAbilitySystemComponent()->MakeOutgoingSpec(DefaultAttributeSet, -1, GetAbilitySystemComponent()->MakeEffectContext()).Data.Get(),
			GetAbilitySystemComponent()
		);
	}

	//StartUp GE
	for (TSubclassOf<UGameplayEffect>& Effect : StartupEffects)
	{
		if (!Effect) continue;
		FGameplayEffectContextHandle ContextHandle = GetAbilitySystemComponent()->MakeEffectContext();
		FGameplayEffectSpecHandle SpecHandle = GetAbilitySystemComponent()->MakeOutgoingSpec(Effect, -1, ContextHandle);
		GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*SpecHandle.Data.Get(), GetAbilitySystemComponent());
	}

	//服务端Give
	if (HasAuthority())
	{
		for (TSubclassOf<UGameplayAbility>& Ability : StartupAbilities)
		{
			if (!Ability) continue;
			FGameplayAbilitySpec AbilitySpec = FGameplayAbilitySpec(Ability, -1, -1, this);
			GetAbilitySystemComponent()->GiveAbilityWithTag(AbilitySpec);
		}
	}

	//服务端Give
	if (HasAuthority())
	{
		for (TSubclassOf<UGameplayAbility>& Ability : StartupDoOnceAbilities)
		{
			if (!Ability) continue;
			FGameplayAbilitySpec AbilitySpec(Ability, -1, -1, this);
			GetAbilitySystemComponent()->GiveAbilityAndActivateOnce(AbilitySpec);
		}
	}
}
