// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/SphereComponent.h"
#include "DriftArtist/AbilitySystem/Abilities/DA_GameplayAbilityBase.h"
#include "GameFramework/Actor.h"
#include "DA_AbilityActorBase.generated.h"

UCLASS()
class DRIFTARTIST_API ADA_AbilityActorBase : public AActor
{
	GENERATED_BODY()

public:
	ADA_AbilityActorBase();

	//球形碰撞体
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Collision")
	TObjectPtr<USphereComponent> SphereComponent;

	// 重叠开始事件
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
	                     const FHitResult& SweepResult);

	// 重叠结束事件
	UFUNCTION(BlueprintCallable, Category = "Collision")
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	FGameplayTagContainer CheckTags;

	// 要授予的技能类
	UPROPERTY(EditDefaultsOnly, Category = "Ability")
	TSubclassOf<UDA_GameplayAbilityBase> AbilityToGrant;

private:
	void GiveAbilityToVehicle(class ADA_VehiclePawnBase* Vehicle);

public:
	virtual void Tick(float DeltaTime) override;
};
