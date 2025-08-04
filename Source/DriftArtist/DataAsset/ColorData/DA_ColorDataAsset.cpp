// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_ColorDataAsset.h"

FLinearColor UDA_ColorDataAsset::GetColorFromTag(const FGameplayTag& InTag) const
{
	for (const FDA_ColorTagData& ColorData : ColorWithTag)
	{
		if (ColorData.Tag == InTag)
		{
			return ColorData.Color;
		}
	}
	return FLinearColor::White;
}

FGameplayTag UDA_ColorDataAsset::GetTagFromColor(const FLinearColor& InColor) const
{
	for (const FDA_ColorTagData& ColorData : ColorWithTag)
	{
		if (ColorData.Color == InColor)
		{
			return ColorData.Tag;
		}
	}
	return FGameplayTag();
}
