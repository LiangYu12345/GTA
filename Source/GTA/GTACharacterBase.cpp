// Fill out your copyright notice in the Description page of Project Settings.


#include "GTACharacterBase.h"
#include "GTACommonData.h"
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

	m_Attributes = CreateDefaultSubobject<UGTAAttributeSet>(TEXT("Ability Set"));
}

void AGTACharacterBase::PossessedBy(AController* controller)
{
	Super::PossessedBy(controller);

	// server GAS init
	if(m_AbilitySystemComponent)
		m_AbilitySystemComponent->InitAbilityActorInfo(this, this);
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

	m_AbilitySystemComponent->InitAbilityActorInfo(this, this);

	if (m_AbilitySystemComponent && InputComponent) {
		const FGameplayAbilityInputBinds Binds(
			"Confirm",
			"Cancel",
			"EGTAAbilityInputID",
			static_cast<int32>(EGTAAbilityInputID::Confirm),
			static_cast<int32>(EGTAAbilityInputID::Cancel)
		);

		m_AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

// Called to bind functionality to input
void AGTACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (m_AbilitySystemComponent && InputComponent) {
		const FGameplayAbilityInputBinds Binds(
			"Confirm",
			"Cancel",
			"EGTAAbilityInputID",
			static_cast<int32>(EGTAAbilityInputID::Confirm),
			static_cast<int32>(EGTAAbilityInputID::Cancel)
		);

		m_AbilitySystemComponent->BindAbilityActivationToInputComponent(InputComponent, Binds);
	}
}

void AGTACharacterBase::AddStartupGameplayAbilities()
{
	// server init game ability
	check(m_AbilitySystemComponent);

	if (m_AbilitySystemComponent && !m_AbilityInitialized) {
		for (TSubclassOf<UGTAGameplayAbility>& startupAbility : m_GameplayAbilitys) {
			m_AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(
				startupAbility, 1, 
				static_cast<int32>(startupAbility.GetDefaultObject()->AbilityInputID),
				this));
		}
	}

	for (const TSubclassOf<UGameplayEffect> GameplayEffect : m_PassiveGameplayEffects) {
		FGameplayEffectContextHandle EffectContext = m_AbilitySystemComponent->MakeEffectContext();
		EffectContext.AddSourceObject(GameplayEffect);

		FGameplayEffectSpecHandle NewHandle = m_AbilitySystemComponent->MakeOutgoingSpec(
			GameplayEffect, 1, EffectContext);

		if (NewHandle.IsValid()) {
			FActiveGameplayEffectHandle ActiveGameplayEffectHandle = m_AbilitySystemComponent->ApplyGameplayEffectSpecToTarget(
				*NewHandle.Data.Get(), m_AbilitySystemComponent);
		}
	}

	m_AbilityInitialized = true;
}

void AGTACharacterBase::HandleDamaged(float DamagedAmount, const FHitResult& HitInfo, const FGameplayTagContainer& DamageTags, AGTACharacterBase* InstigatorCharacter, AActor* DamageCauser)
{
	OnDamaged(DamagedAmount, HitInfo, DamageTags, InstigatorCharacter, DamageCauser);
}

void AGTACharacterBase::HandleHealthChanged(float DelatValue, const FGameplayTagContainer& EventTags)
{
	if(m_AbilityInitialized)
		OnHealthChanged(DelatValue, EventTags);
}

void AGTACharacterBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& outLifttimeProps) const
{
}

UAbilitySystemComponent* AGTACharacterBase::GetAbilitySystemComponent() const
{
	if(IsValid(m_AbilitySystemComponent))
		return m_AbilitySystemComponent;
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

