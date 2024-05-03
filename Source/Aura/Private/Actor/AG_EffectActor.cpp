// Aura Game, Copyright moonabyss. All Rights Reserved.

#include "Actor/AG_EffectActor.h"

#include "AbilitySystem/AG_AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"
#include "Components/SphereComponent.h"

AAG_EffectActor::AAG_EffectActor()
{
    PrimaryActorTick.bCanEverTick = true;

    Sphere = CreateDefaultSubobject<USphereComponent>("Sphere");
    check(Sphere);
    SetRootComponent(Sphere);
    Sphere->SetSphereRadius(100.0f);
    Sphere->OnComponentBeginOverlap.AddDynamic(this, &ThisClass::OnBeginOverlap);
    Sphere->OnComponentEndOverlap.AddDynamic(this, &ThisClass::OnEndOverlap);

    Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
    check(Mesh);
    Mesh->SetupAttachment(GetRootComponent());
}
void AAG_EffectActor::OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    // TODO: Change this to apply a Gameplay Effect. For now use const_cast as a hack.
    if (const auto* ASInterface = Cast<IAbilitySystemInterface>(OtherActor))
    {
        const auto* AttributeSet = Cast<UAG_AttributeSet>(ASInterface->GetAbilitySystemComponent()->GetAttributeSet(UAG_AttributeSet::StaticClass()));
        const_cast<UAG_AttributeSet*>(AttributeSet)->SetHealth(AttributeSet->GetHealth() + 25.0f);
        Destroy();
    }
}
void AAG_EffectActor::OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {}

void AAG_EffectActor::BeginPlay()
{
    Super::BeginPlay();
}
