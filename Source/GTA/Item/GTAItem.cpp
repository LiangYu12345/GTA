// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAItem.h"

UGTAItem::UGTAItem()
{
}

FPrimaryAssetId UGTAItem::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType, GetFName());
}
