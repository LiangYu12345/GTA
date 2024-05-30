// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAGameInstance.h"
#include <Kismet/GameplayStatics.h>

const FString UGTAGameInstance::m_SaveFileName = TEXT("GTASaveData");

UGTAGameInstance::UGTAGameInstance() 
{
	DefaultNaniteVisualization = NAME_None;
	DefaultTemporalAASamples = false;
	CurrentNaniteVisualization = NAME_None;
}

void UGTAGameInstance::Init()
{
	Super::Init();
}

void UGTAGameInstance::Shutdown()
{
	Super::Shutdown();
}

void UGTAGameInstance::OnStart()
{
	Super::OnStart();
}

UGTASaveGame* UGTAGameInstance::LoadGTASaveGame(bool* const bOutSaveGameFound)
{
	m_SaveGame = Cast<UGTASaveGame>(UGameplayStatics::LoadGameFromSlot(m_SaveFileName, 0));
	if (m_SaveGame) {
		if (bOutSaveGameFound != nullptr) {
			*bOutSaveGameFound = true;
		}
	}
	else {
		if (bOutSaveGameFound != nullptr) {
			*bOutSaveGameFound = false;
		}
	}
	return nullptr;
}

void UGTAGameInstance::SaveGTAGameData(bool Async)
{
}

void UGTAGameInstance::ClearSaveGameData()
{
}

void UGTAGameInstance::OnSaveGameDataComplete(const FString& SaveFile, const int32 UserIndex, bool bSuceess)
{
}

void UGTAGameInstance::SetNaniteVisualization(const FString& Visualization)
{
}

void UGTAGameInstance::UpdateDefaultNaniteVisualization()
{
}

void UGTAGameInstance::UpdateDefaultTemporalAASamples()
{
}
