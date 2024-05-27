// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "GTAGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTAGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
public:
	UGTAGameplayAbility();
	
	//UPROPERTY(BlueprintReadOnly, EditAnyWhere, Category = "Abilities")
	//EAbilityInputID	AbilityInputID = EAbilityInputID::None;
};
