// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GTAStoreItem.h"
#include "GTAStoreFoodItem.generated.h"

/**
 * All Food IsConsumable, one is instant effect, other is continue effect(In time)
 */
UCLASS()
class GTA_API UGTAStoreFoodItem : public UGTAStoreItem
{
	GENERATED_BODY()
public:
	UGTAStoreFoodItem();

	void setIsContine(bool val) { if (ItemIsContine == val) return; ItemIsContine = val; }

	bool IsContine() { return ItemIsContine; }

	void setItemHeadlthInstant(float val) { if (ItemHealthInstant == val) return; ItemHealthInstant = val; }

	float getItemHealthInstant() { return ItemHealthInstant; }

	void setItemPowerInstant(float val) { if (ItemPowerInstant == val) return; ItemPowerInstant = val; }

	float getItemPowerInstant() { return ItemPowerInstant; }
public:

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	bool		 ItemIsContine;

	/// <summary>
	///  health Power(physical stamina)
	/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemHealthInstant;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemPowerInstant;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemHealthPositive;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemHealthNegative;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemPowerPositive;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemPowerNegative;
	/// <summary>
	/// attack defence
	/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float	     ItemAttackVal;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemDefenceVal;
	/// <summary>
	/// food contine time
	/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Food")
	float		 ItemCountineTime;
};
