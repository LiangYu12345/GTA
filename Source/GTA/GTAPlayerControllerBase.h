// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/GTAControlsOverlayInterface.h"
#include "UI/GTAUIComponent.h"
#include "Camera/PhotoModeComponent.h"
#include "MassCommonTypes.h"
#include "MassActorSubsystem.h"
#include "GTAPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API AGTAPlayerControllerBase : public APlayerController,
	public IGTAControlsOverlayInterface
{
	GENERATED_BODY()
public:
	AGTAPlayerControllerBase();

	virtual void BeginPlay() override;

	// begin actor interface
	void TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction) override;

	// begin playControll interface
	virtual void PreInitializeComponents() override;
	virtual void PostInitializeComponents() override;
	virtual void UpdateRotation(float DeltaTime) override;
	virtual void SetupInputComponent() override;

	// begin controll interface
	virtual void SetPawn(APawn* InPawn) override;
	virtual void AttachToPawn(APawn* InPawn) override;

	// begin levelInteractorInterface
	//virtual void FinishInteraction() override;
	//virtual void AbortInteraction() override;
	//virtual bool IsInteracting() override;
	//virtual class APawn* GetInteractingPawn() override { return GetPawn(); }
	//virtual void TryToInteract() override; // formal parameter is Level Component
	//virtual bol IsInteractingWith() const override; // ditto

	virtual TMap<UInputAction*, FText> GetInputActionDescriptions_Implementation() const override { return m_InputActionDescriptions; }

	virtual TMap<FKey, FText> GetInputKeyDescriptionOverrides_Implementation() const override {
		return m_InputKeyDescriptionOverrides;
	}
protected:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Controls Overlay")
	TMap<UInputAction*, FText> m_InputActionDescriptions;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Controls Overlay")
	TMap<FKey, FText> m_InputKeyDescriptionOverrides;

	UFUNCTION(BlueprintPure, Category = "UI")
	UGTAUIComponent* GetGTAUIComponent() const { return m_GTAUIComponent; }

	UFUNCTION(BlueprintPure, Category = "Camera")
	UPhotoModeComponent* GetPhoteModeComponent() const { return m_PhotoModeComponent; }
	
	UFUNCTION(BlueprintPure, Category = "Vehicle")
	AActor* GetCurrentPlayerVehicle() const { return m_CurrentPlayerVehicle; }

	const FMassEntityHandle& GetCurrenPlayerVehicleMassHandle() { return m_CurrentPlayerVehicleMassHandle; }
private:
	UPROPERTY(VisibleAnyWhere, Category = "GTA UI")
	UGTAUIComponent* m_GTAUIComponent;

	UPROPERTY(VisibleAnyWhere, Category = "GTA Camera")
	UPhotoModeComponent* m_PhotoModeComponent;

	UPROPERTY(Transient, VisibleAnyWhere, Category = "Vehicle")
	AActor* m_CurrentPlayerVehicle = nullptr;

	FMassEntityHandle m_CurrentPlayerVehicleMassHandle;
};
