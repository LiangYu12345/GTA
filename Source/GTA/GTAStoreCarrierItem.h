// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GTAStoreItem.h"
#include "GTAStoreCarrierItem.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTAStoreCarrierItem : public UGTAStoreItem
{
	GENERATED_BODY()
public:
	UGTAStoreCarrierItem();

public:
	/// <summary>
	/// 
	/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Carrier")
	float		ItemSpeed;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem | Carrier")
	int32		ItemMaxCapacity;

	
};
