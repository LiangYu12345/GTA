// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAAttributeSet.h"
#include "Net/UnrealNetwork.h"

UGTAAttributeSet::UGTAAttributeSet() :
	m_Health(100.0),
	m_Power(100.0),
	m_Location(0)
{
}

void UGTAAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	// Execution represents the life cycle pass data between server and client
	DOREPLIFETIME(UGTAAttributeSet, m_Health);
	DOREPLIFETIME(UGTAAttributeSet, m_Power);
	DOREPLIFETIME(UGTAAttributeSet, m_Location);
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

void UGTAAttributeSet::OnRep_Location(const FGameplayAttributeData& val)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Location, val);
}
