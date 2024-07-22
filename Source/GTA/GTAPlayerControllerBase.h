// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "UI/GTAControlsOverlayInterface.h"
#include "UI/GTAUIComponent.h"
#include "Camera/PhotoModeComponent.h"
#include "MassCommonTypes.h"
#include "MassActorSubsystem.h"
#include "Camera/GTAPlayerCameraManager.h"
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

	UFUNCTION(BlueprintCallable)
	AGTAPlayerCameraManager* GetGTACameraManager() const;

	UFUNCTION(BlueprintCallable, Category = "Vehicle")
	void SetCurrentPlayerVehicle(AActor* NewPlayerVehicle);

	UClass* GetDronePawnClass() const { return m_DronePawnClass.Get(); }

	UFUNCTION(BlueprintCallable)
	float GetCameraTransitionLevelStreamDistance2D() const { return m_CameraTransitionLevelStreamDistance2D; }

	UFUNCTION(BlueprintCallable)
	void SetCanPerformInteractions(bool bNewCanPerformInteractions) { m_bCanPerformInteractions = bNewCanPerformInteractions; }

	UFUNCTION(BlueprintCallable)
	bool GetCanPerformInteractions() const { return m_bCanPerformInteractions; }

	UFUNCTION(BlueprintCallable, Category = "Input")
	void AddInputContext(const bool bForce = false);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void RemoveInputContext();

	UFUNCTION(BlueprintCallable, Category = "Input")
	void AddPawnInputContext(APawn* pawn);

	UFUNCTION(BlueprintCallable, Category = "Input")
	void RemoveInputContext(APawn* pawn);


	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Drone")
	TSubclassOf<APawn> m_DronePawnClass;

	UPROPERTY(Config)
	float m_CameraTransitionLevelStreamDistance2D = 20000.0f;

	UPROPERTY(Config)
	float m_CameraTrasitionWPQueryDistance = 10000.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Input")
	UInputMappingContext* InputMappingContext;

	UPROPERTY(VisibleAnyWhere, Category = "Interaction")
	bool m_bCanPerformInteractions = true;
private:
	UPROPERTY(VisibleAnyWhere, Category = "GTA UI")
	UGTAUIComponent* m_GTAUIComponent;

	UPROPERTY(VisibleAnyWhere, Category = "GTA Camera")
	UPhotoModeComponent* m_PhotoModeComponent;

	UPROPERTY(Transient, VisibleAnyWhere, Category = "Vehicle")
	AActor* m_CurrentPlayerVehicle = nullptr;

	FMassEntityHandle m_CurrentPlayerVehicleMassHandle;
};
