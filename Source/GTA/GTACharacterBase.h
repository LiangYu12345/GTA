// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GTACharacterBase.generated.h"

UCLASS()
class GTA_API AGTACharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGTACharacterBase();

	virtual void PossessedBy(AController* controller) override;
	virtual void UnPossessed() override;
	// pawn possess changed , character info need update
	virtual void OnRep_Controller() override;
	// client¡¢sever synchronous data
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& outLifttimeProps) const override;

	// Implement IAbilitySystemInterface
	UAbilitySystemComponent* GetAbilitySystemComponent() const override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Delegate handles */
	FDelegateHandle InventoryUpdateHandle;
	FDelegateHandle InventoryLoadedHandle;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
