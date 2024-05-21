// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "GTAAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API UGTAAssetManager : public UAssetManager
{
	GENERATED_BODY()
	
public:
	UGTAAssetManager() {};

	virtual void StartInitialLoading() override;
};
