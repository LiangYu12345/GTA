// Fill out your copyright notice in the Description page of Project Settings.


#include "GTACharacterBase.h"
#include "Ability/GTAAbilitySystemComponent.h"

// Sets default values
AGTACharacterBase::AGTACharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	m_AbilityInitialized = false;


	m_AbilitySystemComponent = CreateDefaultSubobject<UGTAAbilitySystemComponent>(TEXT("Ability System"));
	m_AbilitySystemComponent->SetIsReplicated(true);
	m_AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
}

void AGTACharacterBase::PossessedBy(AController* controller)
{
	Super::PossessedBy(controller);


}

void AGTACharacterBase::UnPossessed()
{
}

void AGTACharacterBase::OnRep_Controller()
{
	Super::OnRep_Controller();


}

void AGTACharacterBase::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();
}

void AGTACharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& outLifttimeProps) const
{
}

UAbilitySystemComponent* AGTACharacterBase::GetAbilitySystemComponent() const
{
	return nullptr;
}

// Called when the game starts or when spawned
void AGTACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGTACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGTACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

