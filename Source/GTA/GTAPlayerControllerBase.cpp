// Fill out your copyright notice in the Description page of Project Settings.


#include "GTAPlayerControllerBase.h"
#include <EnhancedInputSubsystems.h>

AGTAPlayerControllerBase::AGTAPlayerControllerBase()
{
}

void AGTAPlayerControllerBase::BeginPlay()
{
}

void AGTAPlayerControllerBase::TickActor(float DeltaSeconds, ELevelTick TickType, FActorTickFunction& ThisTickFunction)
{
}

void AGTAPlayerControllerBase::PreInitializeComponents()
{
}

void AGTAPlayerControllerBase::PostInitializeComponents()
{
}

void AGTAPlayerControllerBase::UpdateRotation(float DeltaTime)
{
}

void AGTAPlayerControllerBase::SetupInputComponent()
{
}

void AGTAPlayerControllerBase::SetPawn(APawn* InPawn)
{
}

void AGTAPlayerControllerBase::AttachToPawn(APawn* InPawn)
{
}

//void AGTAPlayerControllerBase::FinishInteraction()
//{
//}
//
//void AGTAPlayerControllerBase::AbortInteraction()
//{
//}
//
//bool AGTAPlayerControllerBase::IsInteracting()
//{
//	return false;
//}

AGTAPlayerCameraManager* AGTAPlayerControllerBase::GetGTACameraManager() const
{
	return Cast<AGTAPlayerCameraManager>(PlayerCameraManager);
}

void AGTAPlayerControllerBase::SetCurrentPlayerVehicle(AActor* NewPlayerVehicle)
{
}

void AGTAPlayerControllerBase::AddInputContext(const bool bForce)
{
	if (ULocalPlayer* localPlayer = GetLocalPlayer()) {
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) {
			InputSubsystem->AddMappingContext(InputMappingContext, InputPriority);
		}
	}
}

void AGTAPlayerControllerBase::RemoveInputContext()
{
	if (ULocalPlayer* localPlayer = GetLocalPlayer()) {
		if (UEnhancedInputLocalPlayerSubsystem* InputSubsystem = localPlayer->GetSubsystem<UEnhancedInputLocalPlayerSubsystem>()) {
			InputSubsystem->RemoveMappingContext(InputMappingContext);
		}
	}
}

void AGTAPlayerControllerBase::AddPawnInputContext(APawn* pawn)
{
}

void AGTAPlayerControllerBase::RemoveInputContext(APawn* pawn)
{
}


