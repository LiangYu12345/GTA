// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GTASaveGame.h"
#include "GTAGameInstance.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGTAOnSaveGameLoad, const UGTASaveGame* const, LoadedSaveGame);
/**
 * 
 */
UCLASS(Blueprintable)
class GTA_API UGTAGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	UGTAGameInstance();
	
	virtual void Init() override;

	virtual void Shutdown() override;

protected:
	virtual void OnStart() override;

public:

	UFUNCTION(BlueprintPure, Category = "SaveGame")
	UGTASaveGame* GetSaveGame() { return m_SaveGame; }

	UFUNCTION(BlueprintPure, Category = "SaveGame", meta = (DisplayName = "LoadGTASaveGame", AutoCreateRefTerm = "bOutSaveGameFound"))
	UGTASaveGame* K2Node_LoadGTASaveGame(bool& bOutSaveGameFound) { return LoadGTASaveGame(&bOutSaveGameFound); }

	UGTASaveGame* LoadGTASaveGame(bool* const bOutSaveGameFound = nullptr);

	UPROPERTY(BlueprintAssignable)
	FGTAOnSaveGameLoad m_OnSaveGameLoaded;

	UFUNCTION(BlueprintPure, Category = "SaveGame")
	bool IsSaveGameLoaded() const { return m_bSaveGameLoaded; }

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void SaveGTAGameData(bool Async = true);

	UFUNCTION(BlueprintCallable, Category = "SaveGame")
	void ClearSaveGameData();

	void OnSaveGameDataComplete(const FString& SaveFile, const int32 UserIndex, bool bSuceess);


	UFUNCTION(BlueprintCallable, Category = "Nanite", meta = (AutoCreateRefTerm = "Visualization"))
	void SetNaniteVisualization(const FString& Visualization = TEXT("None"));

	UFUNCTION(BlueprintPure, Category = "Nanite")
	const FName& GetCurrentNaniteVisualization() { return CurrentNaniteVisualization; }
private:
	UPROPERTY()
	UGTASaveGame* m_SaveGame = nullptr;

	const static FString m_SaveFileName;

	bool m_bSaveGameLoaded = false;

	/// <summary>
	/// Nanite
	/// </summary>
	FConsoleVariableDelegate NaniteVisualizationSinkHandle;
	FConsoleVariableDelegate TemporalAASamplesSinkHandle;
	void UpdateDefaultNaniteVisualization();
	void UpdateDefaultTemporalAASamples();

	// Transient 
	UPROPERTY(Transient, VisibleAnyWhere, Category = "Nanite")
	FName DefaultNaniteVisualization;

	UPROPERTY(Transient, VisibleAnyWhere, Category = "Nanite")
	int32 DefaultTemporalAASamples;

	UPROPERTY(VisibleAnyWhere, Category = "Nanite")
	FName CurrentNaniteVisualization;
};