// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InputModifiers.h"
#include "GTAInputModifiers.generated.h"

/**
 * player input modify
 */
UCLASS(NotBlueprintable, MinimalAPI, meta = (DisplayName = "Invert Axis"))
class UGTAInputModifierLookSensitivity : public UInputModifier
{
	GENERATED_BODY()
	
	friend class UGTAGameInstanceBase;
public:
	UGTAInputModifierLookSensitivity();

protected:
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayInput, FInputActionValue CurrentValue, float DeltaTime) override;
private:
	inline static FVector Scalar = FVector(1.0f, 1.0f, 1.0f);
};


UCLASS(NotBlueprintable, MinimalAPI, meta = (DisplayName = "Invert Axis"))
class UGTAInputModifierInvertAxis final : public UInputModifier
{
	GENERATED_BODY()

	friend class UGTAGameInstanceBase;
public:
	virtual FInputActionValue ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayInput, FInputActionValue CurrentValue, float DeltaTime) override;

	virtual FLinearColor GetVisualizationColor_Implementation(FInputActionValue CurrentValue, FInputActionValue FinalValue) const override;
private:
	/// <summary>
	/// used bX¡¢bY¡¢bZ reversal player input value
	/// </summary>
	inline static bool bX = false;
	inline static bool bY = false;
	inline static bool bZ = false;
};
