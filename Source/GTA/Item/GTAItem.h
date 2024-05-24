// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "GTAItem.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTAItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UGTAItem();

	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Item")
	FPrimaryAssetType ItemType;

};
