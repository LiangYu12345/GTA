// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(GTAGame, Log, All);

USTRUCT(BlueprintType)
struct FGTAItemData
{



	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "ItemData")
	FPrimaryAssetType ItemType;
};