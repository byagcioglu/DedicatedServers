// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DashboardOverlay.generated.h"

class UWidgetSwitcher;
class UGamePage;

/**
 * 
 */
UCLASS()
class DEDICATEDSERVERS_API UDashboardOverlay : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher> WidgetSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UGamePage> GamePage;

protected:
	virtual void NativeConstruct() override;
	
private:
	UFUNCTION()
	void ShowGamePage();
};
