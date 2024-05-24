// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include <Styling/SlateStyle.h>
#include "../GTAItem.h"
#include "../../GTAAssetManager.h"
#include "GTAStoreItem.generated.h"

class UGTAAssetManager;
/**
 * 
 */
UCLASS()
class GTA_API UGTAStoreItem : public UGTAItem
{
	GENERATED_BODY()
public:

	UGTAStoreItem();
/// <summary>
/// Manager Store Inventory
/// 
/// </summary>
	void InitStoreInventory();

	virtual void AddStoreItem(FPrimaryAssetType& type, FName& name, FText& description, FSlateBrush& icon, float price, int32 max, int32 currentCount);

	void RemoveStoreItem(FPrimaryAssetId& id);

	void UpdateStoreItem(FPrimaryAssetId& id, float price, int32 maxCount, int32 currentCount, FText& description, FSlateBrush icon = FSlateBrush());

/// <summary>
/// Sell¡¢buy-back
/// </summary>
	UFUNCTION(BlueprintCallable)
	void StoreSellItem(FPrimaryAssetId id, int32 count);
	UFUNCTION(BlueprintCallable)
	void StoreBybackItem(FPrimaryAssetId id, int32 count);

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	FName			  ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	FText			  ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	FSlateBrush		  ItemIcon;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	float			  ItemPrice;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	int32			  ItemMaxCount;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	int32			  ItemCurrentCount;

/// <summary>
///  pyhsics volume
/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	float		ItemWidth;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	float		ItemHeight;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	float		ItemLength;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	float		ItemWeight;
protected:
/// <summary>
/// manager this store item
/// </summary>
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "StoreItem")
	TMap<FPrimaryAssetId, UGTAStoreItem *> m_StoreMap;
};
