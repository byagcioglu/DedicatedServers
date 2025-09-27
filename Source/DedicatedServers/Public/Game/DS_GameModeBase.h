// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DS_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API ADS_GameModeBase : public AGameMode
{
	GENERATED_BODY()

protected:
	void TrySeamlessTravel(TSoftObjectPtr<UWorld> DestinationMap);
};
