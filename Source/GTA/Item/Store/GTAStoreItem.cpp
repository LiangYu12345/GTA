// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAStoreItem.h"

UGTAStoreItem::UGTAStoreItem()
{
}

void UGTAStoreItem::InitStoreInventory()
{
}

void UGTAStoreItem::AddStoreItem(FPrimaryAssetType& type, FName& name, FText& description, FSlateBrush& icon, float price, int32 max, int32 currentCount)
{
}

void UGTAStoreItem::RemoveStoreItem(FPrimaryAssetId& id)
{
}

void UGTAStoreItem::UpdateStoreItem(FPrimaryAssetId& id, float price, int32 maxCount, int32 currentCount, FText& description, FSlateBrush icon)
{
}

void UGTAStoreItem::StoreSellItem(FPrimaryAssetId id, int32 count)
{
}

void UGTAStoreItem::StoreBybackItem(FPrimaryAssetId id, int32 count)
{
}
