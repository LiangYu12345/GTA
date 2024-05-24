// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GTAPlayerControllerBase.generated.h"

/**
 * 
 */
UCLASS()
class GTA_API AGTAPlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
public:
	AGTAPlayerControllerBase();

	virtual void BeginPlay() override;
};
