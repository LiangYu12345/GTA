// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAAssetManager.h"
#include "AbilitySystemGlobals.h"

void UGTAAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();

	UAbilitySystemGlobals::Get().InitGlobalData();
}
