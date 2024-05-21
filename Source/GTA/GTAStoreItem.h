// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
//#include "Styling/SlateBrush.h"
#include "GTAStoreItem.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class GTA_API UGTAStoreItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UGTAStoreItem();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	FPrimaryAssetType ItemType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	FName			  ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	FText			  ItemDescription;

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "StoreItem")
	//FSlateBrush		  ItemIcon;


};
