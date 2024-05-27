// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "Net/UnrealNetwork.h"
#include "GTAAttributeSet.generated.h"


#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)
/**
 * 
 */
UCLASS()
class GTA_API UGTAAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UGTAAttributeSet();

	// client¡¢sever synchronous data
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& val);

	UFUNCTION()
	virtual void OnRep_Power(const FGameplayAttributeData& val);

	UFUNCTION()
	virtual void OnRep_Location(const FGameplayAttributeData& val);

	UFUNCTION()
	virtual void OnRep_Euler(const FGameplayAttributeData& val);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Attributes")
	FGameplayAttributeData	m_Health;
	ATTRIBUTE_ACCESSORS(UGTAAttributeSet, m_Health);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Power, Category = "Attributes")
	FGameplayAttributeData	m_Power;	/// physics stamina
	ATTRIBUTE_ACCESSORS(UGTAAttributeSet, m_Power);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Location, Category = "Attributes")
	FGameplayAttributeData	m_Location;
	ATTRIBUTE_ACCESSORS(UGTAAttributeSet, m_Location);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Location, Category = "Attributes")
	FGameplayAttributeData	m_Euler;
	ATTRIBUTE_ACCESSORS(UGTAAttributeSet, m_Euler);
};
