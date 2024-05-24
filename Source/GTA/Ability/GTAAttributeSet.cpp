// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAAttributeSet.h"
#include "Net/UnrealNetwork.h"

UGTAAttributeSet::UGTAAttributeSet()
{
}

void UGTAAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifttimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifttimeProps);

	// Execution represents the life cycle pass data between server and client
	//DOREPLIFETIME(UGTAAttributeSet, m_Health);
}

void UGTAAttributeSet::OnRep_Health(const FGameplayAttributeData& val)
{
	// game ability notify attribute name and val
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Health, val);
}

void UGTAAttributeSet::OnRep_Power(const FGameplayAttributeData& val)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Power, val);
}
