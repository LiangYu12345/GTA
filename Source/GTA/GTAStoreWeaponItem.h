// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GTAStoreItem.h"
#include "GTAStoreWeaponItem.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTAStoreWeaponItem : public UGTAStoreItem
{
	GENERATED_BODY()
public:

public:

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Weapon")
	float	     ItemAttackVal;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Weapon")
	float		 ItemAttackDistance;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Weapon")
	float		 ItemDefenceVal;

	
};
