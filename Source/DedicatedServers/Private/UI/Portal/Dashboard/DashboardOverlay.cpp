// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/DashboardOverlay.h"
#include "UI/Portal/Dashboard/GamePage.h"
#include "Components/WidgetSwitcher.h"

void UDashboardOverlay::NativeConstruct()
{
	Super::NativeConstruct();
	ShowGamePage();
}

void UDashboardOverlay::ShowGamePage()
{
	WidgetSwitcher->SetActiveWidget(GamePage);
}
