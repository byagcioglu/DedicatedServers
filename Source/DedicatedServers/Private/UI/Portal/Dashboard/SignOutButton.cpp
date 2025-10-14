#include "UI/Portal/Dashboard//SignOutButton.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Player/DSLocalPlayerSubsystem.h"
#include "UI/Portal/PortalManager.h"

void USignOutButton::NativeConstruct()
{
	Super::NativeConstruct();

	PortalManager = NewObject<UPortalManager>(this, PortalManagerClass);
	Button_SignOut->OnClicked.AddDynamic(this, &USignOutButton::SignOutButton_OnClicked);
}

void USignOutButton::NativePreConstruct()
{
	Super::NativePreConstruct();
}

void USignOutButton::SignOutButton_OnClicked()
{
	Button_SignOut->SetIsEnabled(false);

	check(PortalManager);
	UDSLocalPlayerSubsystem* LocalPlayerSubsystem = GetLocalPlayerSubsystem();
	if (IsValid(LocalPlayerSubsystem))
	{
		FDSAuthenticationResult AuthResult = LocalPlayerSubsystem->GetAuthResult();
		PortalManager->SignOut(AuthResult.AccessToken);
	}
}

UDSLocalPlayerSubsystem* USignOutButton::GetLocalPlayerSubsystem()
{
	APlayerController* PlayerController = GetOwningPlayer();
	if (IsValid(PlayerController) && IsValid(PlayerController->GetLocalPlayer()))
	{
		UDSLocalPlayerSubsystem* LocalPlayerSubsystem = PlayerController->GetLocalPlayer()->GetSubsystem<UDSLocalPlayerSubsystem>();
		if (IsValid(LocalPlayerSubsystem))
		{
			return LocalPlayerSubsystem;
		}
	}
	return nullptr;
}