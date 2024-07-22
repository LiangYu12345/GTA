// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "Item/GTAItem.h"
#include "GTASaveGame.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTASaveGame : public USaveGame
{
	GENERATED_BODY()
	
public:
	UGTASaveGame();

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "SaveGame")
	TMap<FPrimaryAssetId, UGTAItem> m_InventoryData;

	UPROPERTY(VisibleAnyWhere, BlueprintReadWrite, Category = "SaveGame")
	TMap<>
};
