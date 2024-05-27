// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include <GameplayEffect.h>
#include "Net/UnrealNetwork.h"
#include "GTACharacterBase.generated.h"

class UGTAAbilitySystemComponent;
class UGTAGameplayAbility;
class UGTAAttributeSet;

UCLASS()
class GTA_API AGTACharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGTACharacterBase();

	virtual void PossessedBy(AController* controller) override;
	virtual void UnPossessed() override;
	// pawn possess changed , character info need update
	virtual void OnRep_Controller() override;
	
	virtual void OnRep_PlayerState() override;

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

	// initial game cover game effect
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayEffect>> m_PassiveGameplayEffects;

	// offer character game ability
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Abilities")
	TArray<TSubclassOf<UGTAGameplayAbility>> m_GameplayAbilitys;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "AbilitySystemComponent")
	TObjectPtr<UGTAAbilitySystemComponent> m_AbilitySystemComponent;

	UPROPERTY(BlueprintReadOnly, Category = "Attributes")
	TObjectPtr<UGTAAttributeSet> m_Attributes;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Abilities")
	uint8	m_AbilityInitialized;
};
