#include "UI/Portal/PortalHUD.h"
#include "UI/Portal/SignIn/SignInOverlay.h"
#include "Blueprint/UserWidget.h"
#include "UI/Portal/Dashboard/DashboardOverlay.h"
#include "UI/GameSessions/GameSessionsManager.h"


void APortalHUD::BeginPlay()
{
	Super::BeginPlay();

	APlayerController* OwningPlayerController = GetOwningPlayerController();
    
	SignInOverlay = CreateWidget<USignInOverlay>(OwningPlayerController, SignInOverlayClass);
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->AddToViewport();
	}

	FInputModeGameAndUI InputModeData;
	OwningPlayerController->SetInputMode(InputModeData);
	OwningPlayerController->SetShowMouseCursor(true);
}

void APortalHUD::OnSignIn()
{
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->RemoveFromParent();
	}
	APlayerController* OwningPlayerController = GetOwningPlayerController();
	DashboardOverlay = CreateWidget<UDashboardOverlay>(OwningPlayerController, DashboardOverlayClass);
	if (IsValid(DashboardOverlay))
	{
		DashboardOverlay->AddToViewport();
	}

	GameSessionsManager=NewObject<UGameSessionsManager>(this, GameSessionsManagerClass);
	GameSessionsManager->JoinGameSession();
}

void APortalHUD::OnSignOut()
{
	if (IsValid(DashboardOverlay))
	{
		DashboardOverlay->RemoveFromParent();
	}
	APlayerController* OwningPlayerController = GetOwningPlayerController();
	SignInOverlay = CreateWidget<USignInOverlay>(OwningPlayerController, SignInOverlayClass);
	if (IsValid(SignInOverlay))
	{
		SignInOverlay->AddToViewport();
	}
}