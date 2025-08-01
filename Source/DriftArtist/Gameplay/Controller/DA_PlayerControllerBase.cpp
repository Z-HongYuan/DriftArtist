// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_PlayerControllerBase.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "DriftArtist/Input/DA_EnhanceInputComponent.h"
#include "GameFramework/GameplayCamerasPlayerCameraManager.h"

ADA_PlayerControllerBase::ADA_PlayerControllerBase()
{
	PlayerCameraManagerClass = AGameplayCamerasPlayerCameraManager::StaticClass();
}

void ADA_PlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

	/*if (IsLocalController()) //在本地控制器中添加Mapping
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(DefaultAbilityContext, 10);
			SetInputMode(FInputModeGameOnly());
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AGenshinPlayerController::BeginPlay() UEnhancedInputLocalPlayerSubsystem is nullptr"));
		}
	}*/
}

void ADA_PlayerControllerBase::SetupInputComponent()
{
	Super::SetupInputComponent();

	/*if (IsLocalController())
	{
		if (UDA_EnhanceInputComponent* DA_EnhanceInputComponent = CastChecked<UDA_EnhanceInputComponent>(InputComponent))
		{
			DA_EnhanceInputComponent->BindAbilityAction(
				InputDataAsset,
				this,
				&ThisClass::AbilityInputTagPressed,
				&ThisClass::AbilityInputTagReleased,
				&ThisClass::AbilityInputTagHeld
			);
		}
	}*/
}

/*
void ADA_PlayerControllerBase::AbilityInputTagPressed(FGameplayTag InputTag)
{
	if (GetASC() == nullptr) return;
	GetASC()->AbilityInputTagPressed(InputTag);
}

void ADA_PlayerControllerBase::AbilityInputTagReleased(FGameplayTag InputTag)
{
	if (GetASC() == nullptr) return;
	GetASC()->AbilityInputTagReleased(InputTag);
}

void ADA_PlayerControllerBase::AbilityInputTagHeld(FGameplayTag InputTag)
{
	if (GetASC() == nullptr) return;
	GetASC()->AbilityInputTagHeld(InputTag);
}

UDA_AbilitySystemComponent* ADA_PlayerControllerBase::GetASC()
{
	//如果ASC无效或者空指针,重新缓存一下
	if (AvatarASC == nullptr or !AvatarASC.IsValid())
	{
		AvatarASC = Cast<UDA_AbilitySystemComponent>(UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(GetPawn()));
	}
	return AvatarASC.Get();
}
*/
