// No Copyright.

#include "Actor/AuraEffectActor.h"
#include "Components/SphereComponent.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshComp"));
	SetRootComponent(Mesh);
	
	Collision = CreateDefaultSubobject<USphereComponent>(FName("SphereComp"));
	Collision->SetupAttachment(Mesh);
}

void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AAuraEffectActor::OnBeginOverlap);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AAuraEffectActor::OnEndOverlap);
}

void AAuraEffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	const UAbilitySystemComponent* AbilitySystem = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(OtherActor);
	if (!AbilitySystem) return;
	
	const UAttributeSet* AttributeSet = AbilitySystem->GetAttributeSet(UAuraAttributeSet::StaticClass());
	if (!AttributeSet) return;
	
	const UAuraAttributeSet* AuraAttributeSet = Cast<UAuraAttributeSet>(AttributeSet);
	if (!AuraAttributeSet) return;
	
	UAuraAttributeSet* MutableAuraAttributeSet = const_cast<UAuraAttributeSet*>(AuraAttributeSet);
	MutableAuraAttributeSet->SetHealth(AuraAttributeSet->GetHealth() + 25.f);
	MutableAuraAttributeSet->SetMana(AuraAttributeSet->GetMana() - 25.f);
	Destroy();
}

void AAuraEffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	
}
