#include "UI/HTTP/HTTPRequestTypes.h"
#include "DedicatedServers/DedicatedServers.h"

namespace HTTPStatusMessages
{
	const FString SomethingWentWrong{TEXT("Something went wrong!")};
}

void FDSCodeDeliveryDetails::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("CodeDeliveryDetails:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("   AttributeName: %s"), *AttributeName);
	UE_LOG(LogDedicatedServers, Log, TEXT("   DeliveryMedium: %s"), *DeliveryMedium);
	UE_LOG(LogDedicatedServers, Log, TEXT("   Destination: %s"), *Destination);
}

void FDSSignUpResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("FDSSignUpResponse Details:"));
	CodeDeliveryDetails.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("UserConfirmed: %s"), UserConfirmed ? TEXT("true") : TEXT("false"));
	UE_LOG(LogDedicatedServers, Log, TEXT("UserSub: %s"), *UserSub);
}

void FDSNewDeviceMetaData::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("NewDeviceMetadata:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("   DeviceGroupKey: %s"), *DeviceGroupKey);
	UE_LOG(LogDedicatedServers, Log, TEXT("   DeviceKey: %s"), *DeviceKey);
}

void FDSAuthenticationResult::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("AuthenticationResult:"));
	UE_LOG(LogDedicatedServers, Log, TEXT("   AccessToken: %s"), *AccessToken);
	UE_LOG(LogDedicatedServers, Log, TEXT("   ExpiresIn: %d"), ExpiresIn);
	UE_LOG(LogDedicatedServers, Log, TEXT("   IdToken: %s"), *IdToken);
	NewDeviceMetadata.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("   RefreshToken: %s"), *RefreshToken);
	UE_LOG(LogDedicatedServers, Log, TEXT("   TokenType: %s"), *TokenType);
}

void FDSChallengeParameters::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("ChallengeParameters:"));
	for (const auto& Param : Parameters)
	{
		UE_LOG(LogDedicatedServers, Log, TEXT("   %s: %s"), *Param.Key, *Param.Value);
	}
}

void FDSInitiateAuthResponse::Dump() const
{
	UE_LOG(LogDedicatedServers, Log, TEXT("FDSSignUpResponse Details:"));
	AuthenticationResult.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("ChallengeName: %s"), *ChallengeName);
	ChallengeParameters.Dump();
	UE_LOG(LogDedicatedServers, Log, TEXT("Session: %s"), *Session);
	UE_LOG(LogDedicatedServers, Log, TEXT("email: %s"), *email);
}