// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAAssetManager.h"
#include "AbilitySystemGlobals.h"

UGTAAssetManager& UGTAAssetManager::Get()
{
	UGTAAssetManager* instance = Cast<UGTAAssetManager>(GEngine->AssetManager);

	if (instance) 
	{
		return *instance;
	}
	else 
	{
		UE_LOG(LogTemp, Fatal, TEXT("Asset Manager is not loaded"));
		return *NewObject<UGTAAssetManager>();
	}
}

void UGTAAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
