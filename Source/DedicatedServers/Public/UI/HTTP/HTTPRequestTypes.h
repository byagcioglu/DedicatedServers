#pragma once

#include "HTTPRequestTypes.generated.h"

namespace HTTPStatusMessages
{
	extern DEDICATEDSERVERS_API const FString SomethingWentWrong;
}

USTRUCT()
struct FDSCodeDeliveryDetails
{
	GENERATED_BODY()

	UPROPERTY()
	FString AttributeName{};

	UPROPERTY()
	FString DeliveryMedium{};

	UPROPERTY()
	FString Destination{};

	void Dump() const;
};

USTRUCT()
struct FDSSignUpResponse
{
	GENERATED_BODY()

	UPROPERTY()
	FDSCodeDeliveryDetails CodeDeliveryDetails{};

	UPROPERTY()
	bool UserConfirmed{};

	UPROPERTY()
	FString UserSub{};

	void Dump() const;
};

USTRUCT()
struct FDSNewDeviceMetaData
{
	GENERATED_BODY()

	UPROPERTY()
	FString DeviceGroupKey{};

	UPROPERTY()
	FString DeviceKey{};

	void Dump() const;
};

USTRUCT()
struct FDSAuthenticationResult
{
	GENERATED_BODY()

	UPROPERTY()
	FString AccessToken{};

	UPROPERTY()
	int32 ExpiresIn{};

	UPROPERTY()
	FString IdToken{};

	UPROPERTY()
	FDSNewDeviceMetaData NewDeviceMetadata{};

	UPROPERTY()
	FString RefreshToken{};

	UPROPERTY()
	FString TokenType{};

	void Dump() const;
};

// ChallengeParameters struct
USTRUCT()
struct FDSChallengeParameters
{
	GENERATED_BODY()

	UPROPERTY()
	TMap<FString, FString> Parameters{};

	void Dump() const;
};

USTRUCT()
struct FDSInitiateAuthResponse
{
	GENERATED_BODY()

	UPROPERTY()
	FDSAuthenticationResult AuthenticationResult{};

	UPROPERTY()
	FString ChallengeName{};

	UPROPERTY()
	FDSChallengeParameters ChallengeParameters{};

	UPROPERTY()
	FString Session{};

	UPROPERTY()
	FString email{};

	void Dump() const;
};