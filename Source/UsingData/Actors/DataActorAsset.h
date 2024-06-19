// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataActorBase.h"
#include "DataActorAsset.generated.h"

/**
 * 
 */
UCLASS()
class USINGDATA_API ADataActorAsset : public ADataActorBase
{
	GENERATED_BODY()

protected:

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	
	
};
