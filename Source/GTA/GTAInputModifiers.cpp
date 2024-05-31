// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAInputModifiers.h"

UGTAInputModifierLookSensitivity::UGTAInputModifierLookSensitivity()
{
}

FInputActionValue UGTAInputModifierLookSensitivity::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayInput, FInputActionValue CurrentValue, float DeltaTime)
{
	if (CurrentValue.GetValueType() != EInputActionValueType::Boolean) {
		return CurrentValue.Get<FInputActionValue::Axis3D>() * Scalar;
	}

	return CurrentValue;
}

FInputActionValue UGTAInputModifierInvertAxis::ModifyRaw_Implementation(const UEnhancedPlayerInput* PlayInput, FInputActionValue CurrentValue, float DeltaTime)
{
	const FInputActionValue::Axis3D RawValue =  CurrentValue.Get<FInputActionValue::Axis3D>();
	return FInputActionValue::Axis3D(bX ? -RawValue.X : RawValue.X, bY ? -RawValue.Y : RawValue.Y, bZ ? -RawValue.Z : RawValue.Z);
}

FLinearColor UGTAInputModifierInvertAxis::GetVisualizationColor_Implementation(FInputActionValue CurrentValue, FInputActionValue FinalValue) const
{
	const FInputActionValue::Axis3D Current = CurrentValue.Get<FInputActionValue::Axis3D>();
	const FInputActionValue::Axis3D Final = FinalValue.Get<FInputActionValue::Axis3D>();
	return FLinearColor(Current.X != Final.X ? 1.0f : 0.0f, Current.Y != Final.Y ? 1.0f : 0.0f, Current.Z != Final.Z ? 1.0f : 0.0f);
}
