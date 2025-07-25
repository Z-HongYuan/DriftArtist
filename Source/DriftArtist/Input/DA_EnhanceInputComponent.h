// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DA_InputDataAsset.h"
#include "EnhancedInputComponent.h"
#include "DA_EnhanceInputComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class DRIFTARTIST_API UDA_EnhanceInputComponent : public UEnhancedInputComponent
{
	GENERATED_BODY()

public:
	UDA_EnhanceInputComponent();

	template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
	void BindAbilityAction(const UDA_InputDataAsset* InputDataAsset,
	                       UserClass* Object,
	                       PressedFuncType PressedFunc,
	                       ReleasedFuncType ReleasedFunc,
	                       HeldFuncType HeldFunc);

protected:
	virtual void BeginPlay() override;

public:
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};

template <class UserClass, typename PressedFuncType, typename ReleasedFuncType, typename HeldFuncType>
void UDA_EnhanceInputComponent::BindAbilityAction(
	const UDA_InputDataAsset* InputDataAsset,
	UserClass* Object,
	PressedFuncType PressedFunc,
	ReleasedFuncType ReleasedFunc,
	HeldFuncType HeldFunc)
{
	check(InputDataAsset);

	for (const FDA_InputAction& ActionData : InputDataAsset->AbilityInputActions)
	{
		if (ActionData.InputAction and ActionData.InputTag.IsValid())
		{
			if (HeldFunc)
			{
				BindAction(ActionData.InputAction, ETriggerEvent::Triggered, Object, HeldFunc, ActionData.InputTag);
			}
			if (PressedFunc)
			{
				BindAction(ActionData.InputAction, ETriggerEvent::Started, Object, PressedFunc, ActionData.InputTag);
			}
			if (ReleasedFunc)
			{
				BindAction(ActionData.InputAction, ETriggerEvent::Completed, Object, ReleasedFunc, ActionData.InputTag);
			}
		}
	}
}
