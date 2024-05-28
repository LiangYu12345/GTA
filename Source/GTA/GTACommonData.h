#pragma once
#include <Engine/Blueprint.h>

UENUM(BlueprintType)
enum class EGTAAnimationDirection : uint8
{
	Down,
	Up,
	Right,
	Left,
	DownRight,
	DownLeft,
	UpRight,
	UpLeft
};

UENUM(BlueprintType)
enum class EGTAAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Punch
};