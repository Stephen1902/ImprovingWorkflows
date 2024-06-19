// Fill out your copyright notice in the Description page of Project Settings.


#include "DataActorBase.h"
#include "Components/SphereComponent.h"

// Sets default values
ADataActorBase::ADataActorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereCollider = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	SphereCollider->SetSphereRadius(50.0f);
	RootComponent = SphereCollider;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(SphereCollider); 

}

// Called when the game starts or when spawned
void ADataActorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADataActorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (mFloatCurve)
	{
		if (mCurrentRotation <= mRotationDuration)
		{
			mCurrentRotation += DeltaTime;
			const float TimeRatio = FMath::Clamp(mCurrentRotation / mRotationDuration, 0.f, 1.0f);
			const float RotationAlpha = mFloatCurve->GetFloatValue(TimeRatio);

			const FRotator CurrentRotation = FMath::Lerp(FRotator::ZeroRotator, FRotator(0.f, 180.f, 0.f), RotationAlpha);
			SetActorRotation(CurrentRotation);
		}
		else
		{
			mCurrentRotation = 0.f;
		}
	}
}

