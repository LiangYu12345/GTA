// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAAttributeSet.h"
#include "GameplayEffectExtension.h"
#include "../GTACharacterBase.h"
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
	DOREPLIFETIME(UGTAAttributeSet, m_MaxHealth);
	DOREPLIFETIME(UGTAAttributeSet, m_Power);
	DOREPLIFETIME(UGTAAttributeSet, m_Location);
	DOREPLIFETIME(UGTAAttributeSet, m_Euler);
}

void UGTAAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == Getm_MaxHealthAttribute()) {
		AdjustAttributeForMaxChange(m_Health, m_MaxHealth, NewValue, Getm_HealthAttribute());
	}
}


void UGTAAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FGameplayEffectContextHandle Context = Data.EffectSpec.GetContext();
	UAbilitySystemComponent* Source = Context.GetOriginalInstigatorAbilitySystemComponent();
	const FGameplayTagContainer& SourceTags = *Data.EffectSpec.CapturedSourceTags.GetAggregatedTags();

	float DeltaValue{ 0.0f };
	if (Data.EvaluatedData.ModifierOp == EGameplayModOp::Type::Additive) {
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	AGTACharacterBase* TargetCharacter{ nullptr };

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid()) {
		AActor* TargetActor{ nullptr };
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetCharacter = Cast<AGTACharacterBase>(TargetActor);
	}

	if (Data.EvaluatedData.Attribute == Getm_HealthAttribute()) {
		Setm_Health(FMath::Clamp(Getm_Health(), 0.0f, Getm_MaxHealth()));

		if (TargetCharacter) {
			TargetCharacter->HandleHealthChanged(DeltaValue, SourceTags);
		}
	}
}

void UGTAAttributeSet::AdjustAttributeForMaxChange(const FGameplayAttributeData& AffectedAttribute, const FGameplayAttributeData& MaxAttribute, float NewMaxValue, const FGameplayAttribute& AffectedAttributeProperty) const
{
	UAbilitySystemComponent* AbilityComp = GetOwningAbilitySystemComponent();
	const float CurrentMaxValue = MaxAttribute.GetCurrentValue();
	if (!FMath::IsNearlyEqual(CurrentMaxValue, NewMaxValue) && AbilityComp){
		const float CurrentValue = AffectedAttribute.GetCurrentValue();
		const float NewDelta = CurrentValue > 0.0f ? CurrentValue * NewMaxValue / CurrentMaxValue - CurrentValue : NewMaxValue;
	
		AbilityComp->ApplyModToAttributeUnsafe(AffectedAttributeProperty, EGameplayModOp::Additive, NewMaxValue);
	}
}

void UGTAAttributeSet::OnRep_Health(const FGameplayAttributeData& val)
{
	// game ability notify attribute name and val
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Health, val);
}

void UGTAAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& val)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_MaxHealth, val);
}

void UGTAAttributeSet::OnRep_Power(const FGameplayAttributeData& val)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Power, val);
}

void UGTAAttributeSet::OnRep_Location(const FGameplayAttributeData& val)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Location, val);
}

void UGTAAttributeSet::OnRep_Euler(const FGameplayAttributeData& val)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UGTAAttributeSet, m_Euler, val);
}
