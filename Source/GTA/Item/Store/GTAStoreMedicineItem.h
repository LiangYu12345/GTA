// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GTAStoreItem.h"
#include "GTAStoreMedicineItem.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTAStoreMedicineItem : public UGTAStoreItem
{
	GENERATED_BODY()
	
public:
	UGTAStoreMedicineItem();

public:
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Medicine")
	bool		ItemIsContinue;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Medicine")
	float		ItemHealthInstant;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Medicine")
	float		ItemHealthPositive;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Medicine")
	int32		ItemContinueTime;
};
