#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "SignOutButton.generated.h"

class UButton;
class UTextBlock;
class UPortalManager;
class UDSLocalPlayerSubsystem;
UCLASS()
class DEDICATEDSERVERS_API USignOutButton : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton> Button_SignOut;
	
	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UPortalManager> PortalManagerClass;

protected:
	virtual void NativeConstruct() override;
	virtual void NativePreConstruct() override;
	
	UFUNCTION()
	void SignOutButton_OnClicked();
	
private:
	UPROPERTY()
	TObjectPtr<UPortalManager> PortalManager;

	UDSLocalPlayerSubsystem* GetLocalPlayerSubsystem();
};