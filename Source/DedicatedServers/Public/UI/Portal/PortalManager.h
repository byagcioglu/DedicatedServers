#pragma once

#include "CoreMinimal.h"
#include "UI/HTTP/HTTPRequestManager.h"
#include "Interfaces/IHttpRequest.h"
#include "UI/HTTP/HTTPRequestTypes.h"
#include "PortalManager.generated.h"

UCLASS()
class DEDICATEDSERVERS_API UPortalManager : public UHTTPRequestManager
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FAPIStatusMessage SignUpStatusMessageDelegate;

	void SignUp(const FString& Username, const FString& Password, const FString& Email);

	FDSSignUpResponse LastSignUpResponse;
	FString LastUsername;

private:
	void SignUp_Response(FHttpRequestPtr Request, FHttpResponsePtr Response, bool bWasSuccessful);
};