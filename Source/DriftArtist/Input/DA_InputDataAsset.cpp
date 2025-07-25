// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_InputDataAsset.h"

const UInputAction* UDA_InputDataAsset::GetInputActionFromTag(const FGameplayTag& InputTag) const
{
	for (const FDA_InputAction& AbilityInput : AbilityInputActions)
	{
		if (AbilityInput.InputTag == InputTag)
		{
			return AbilityInput.InputAction;
		}
	}
	return nullptr;
}

FGameplayTag UDA_InputDataAsset::GetInputTagFromAction(const UInputAction* InputAction) const
{
	for (const FDA_InputAction& AbilityInput : AbilityInputActions)
	{
		if (AbilityInput.InputAction == InputAction)
		{
			return AbilityInput.InputTag;
		}
	}
	return FGameplayTag();
}
