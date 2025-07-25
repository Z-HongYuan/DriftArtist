// Fill out your copyright notice in the Description page of Project Settings.


#include "DA_AttributeSetBase.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UDA_AttributeSetBase::UDA_AttributeSetBase()
{
}

void UDA_AttributeSetBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	/*`REPNOTIFY_Always` 告诉 `OnRep` 函数在本地值已经等于从服务器复制的值（由于预测）时触发。默认情况下，如果本地值与从服务器复制的值相同，则不会触发 `OnRep` 函数。*/
	DOREPLIFETIME_CONDITION_NOTIFY(UDA_AttributeSetBase, Health, COND_None, REPNOTIFY_Always); //终身复制
	DOREPLIFETIME_CONDITION_NOTIFY(UDA_AttributeSetBase, MaxHealth, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UDA_AttributeSetBase, DyeStuff, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UDA_AttributeSetBase, MaxDyeStuff, COND_None, REPNOTIFY_Always);
}

void UDA_AttributeSetBase::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxHealth());
	}
	if (Attribute == GetDyeStuffAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxDyeStuff());
	}
}

void UDA_AttributeSetBase::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetDyeStuffAttribute())
	{
		SetDyeStuff(FMath::Clamp(GetDyeStuff(), 0.0f, GetMaxDyeStuff()));
	}
}

void UDA_AttributeSetBase::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDA_AttributeSetBase, Health, OldHealth);
}

void UDA_AttributeSetBase::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDA_AttributeSetBase, MaxHealth, OldMaxHealth);
}

void UDA_AttributeSetBase::OnRep_DyeStuff(const FGameplayAttributeData& OldDyeStuff)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDA_AttributeSetBase, DyeStuff, OldDyeStuff);
}

void UDA_AttributeSetBase::OnRep_MaxDyeStuff(const FGameplayAttributeData& OldMaxDyeStuff)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UDA_AttributeSetBase, MaxDyeStuff, OldMaxDyeStuff);
}
