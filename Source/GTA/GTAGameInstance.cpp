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

		m_OnSaveGameLoaded.Broadcast(m_SaveGame);
	}
	else {
		if (bOutSaveGameFound != nullptr) {
			*bOutSaveGameFound = false;
		}
		UE_LOG(GTAGame, Warning, TEXT("%s: failed to load save data. Most likely no save data exists yet."), ANSI_TO_TCHAR(__func__));

		m_SaveGame = Cast<UGTASaveGame>(UGameplayStatics::CreateSaveGameObject(UGTASaveGame::StaticClass()));

		if (m_SaveGame == nullptr) {
			UE_LOG(GTAGame, Warning, TEXT("%s: failed to create a new save game."), ANSI_TO_TCHAR(__func__));
		}
	}
	return m_SaveGame;
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
