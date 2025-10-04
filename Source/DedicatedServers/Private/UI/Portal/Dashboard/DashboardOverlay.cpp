// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Portal/Dashboard/DashboardOverlay.h"
#include "UI/Portal/Dashboard/GamePage.h"
#include "UI/Portal/Dashboard/CareerPage.h"
#include "Components/WidgetSwitcher.h"
#include "UI/GameStats/GameStatsManager.h"
#include "Components/Button.h"

void UDashboardOverlay::NativeConstruct()
{
	Super::NativeConstruct();

	GameStatsManager = NewObject<UGameStatsManager>(this, GameStatsManagerClass);
	GameStatsManager->OnRetrieveMatchStatsResponseReceived.AddDynamic(CareerPage, &UCareerPage::OnRetrieveMatchStats);
	GameStatsManager->RetrieveMatchStatsStatusMesssage.AddDynamic(CareerPage, &UCareerPage::SetStatusMessage);
	
	Button_Game->OnClicked.AddDynamic(this, &UDashboardOverlay::ShowGamePage);
	Button_Career->OnClicked.AddDynamic(this, &UDashboardOverlay::ShowCareerPage);
	
	ShowGamePage();
}

void UDashboardOverlay::ShowGamePage()
{
	WidgetSwitcher->SetActiveWidget(GamePage);
}

void UDashboardOverlay::ShowCareerPage()
{
	DisableButton(Button_Career);
	WidgetSwitcher->SetActiveWidget(CareerPage);
	GameStatsManager->RetrieveMatchStats();
}

void UDashboardOverlay::DisableButton(UButton* Button) const
{
	Button_Game->SetIsEnabled(true);
	Button_Career->SetIsEnabled(true);
	Button_Leaderboard->SetIsEnabled(true);
	Button->SetIsEnabled(false);
}
