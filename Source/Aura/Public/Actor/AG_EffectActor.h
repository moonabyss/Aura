// Aura Game, Copyright moonabyss. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "AG_EffectActor.generated.h"

class USphereComponent;

UCLASS()
class AURA_API AAG_EffectActor : public AActor
{
    GENERATED_BODY()

public:
    AAG_EffectActor();

    UFUNCTION()
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

    UFUNCTION()
    void OnEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY(VisibleAnywhere)
    TObjectPtr<UStaticMeshComponent> Mesh;

    UPROPERTY(VisibleAnywhere)
    TObjectPtr<USphereComponent> Sphere;
};
