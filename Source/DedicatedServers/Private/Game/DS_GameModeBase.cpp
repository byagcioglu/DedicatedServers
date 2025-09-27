// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/DS_GameModeBase.h"
#include "Kismet/GameplayStatics.h"

void ADS_GameModeBase::TrySeamlessTravel(TSoftObjectPtr<UWorld> DestinationMap)
{
	const FString MapName = DestinationMap.ToSoftObjectPath().GetAssetName();
	if (GIsEditor)
	{
		UGameplayStatics::OpenLevelBySoftObjectPtr(this, DestinationMap);
	}
	else
	{
		GetWorld()->ServerTravel(MapName);
	}
}