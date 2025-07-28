// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_AbilityActorBase.h"

#include "DriftArtist/Vehicle/DA_VehiclePawnBase.h"


ADA_AbilityActorBase::ADA_AbilityActorBase()
{
	PrimaryActorTick.bCanEverTick = false;

	SphereComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
	SetRootComponent(SphereComponent);

	// 启用碰撞
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
}

void ADA_AbilityActorBase::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                                           const FHitResult& SweepResult)
{
	// 检查是否是有效的车辆
	if (ADA_VehiclePawnBase* VehiclePawn = Cast<ADA_VehiclePawnBase>(OtherActor))
	{
		// 给车辆添加技能
		GiveAbilityToVehicle(VehiclePawn);
	}
}

void ADA_AbilityActorBase::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void ADA_AbilityActorBase::BeginPlay()
{
	Super::BeginPlay();

	// 绑定重叠事件
	if (SphereComponent)
	{
		SphereComponent->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnSphereOverlap);
		SphereComponent->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnSphereEndOverlap);
	}
}

void ADA_AbilityActorBase::GiveAbilityToVehicle(class ADA_VehiclePawnBase* Vehicle)
{
	if (!Vehicle || !AbilityToGrant) return;
	UDA_AbilitySystemComponent* ASC = Vehicle->GetAbilitySystemComponent();
	if (!ASC) return;

	TArray<FGameplayAbilitySpecHandle> ActivatableAbilities;
	ASC->FindAllAbilitiesWithTags(ActivatableAbilities, CheckTags);
	int32 ActiveAbilityCount = ActivatableAbilities.Num();

	if (ActiveAbilityCount < 2)
	{
		ASC->K2_GiveAbilityWithTag(AbilityToGrant);
	}
	else
	{
		ASC->ClearAbility(ActivatableAbilities[1]);

		ASC->K2_GiveAbilityWithTag(AbilityToGrant);
	}
	Destroy();
}

void ADA_AbilityActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
