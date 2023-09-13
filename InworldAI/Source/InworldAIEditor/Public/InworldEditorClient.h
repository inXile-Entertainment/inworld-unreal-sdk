/**
 * Copyright 2022 Theai, Inc. (DBA Inworld)
 *
 * Use of this source code is governed by the Inworld.ai Software Development Kit License Agreement
 * that can be found in the LICENSE.md file or at https://www.inworld.ai/sdk-license
 */

#pragma once

#include "InworldEditorClient.generated.h"

namespace Inworld
{
	class FEditorClient;
}

USTRUCT()
struct FInworldEditorClientOptions
{
public:
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Editor Client")
	FString ServerUrl;

	UPROPERTY(EditAnywhere, Category = "Editor Client")
	FString ExchangeToken;
};

USTRUCT()
struct INWORLDAIEDITOR_API FInworldEditorClient
{
public:
	GENERATED_BODY()

	void Init();
	void Destroy();

	void RequestFirebaseToken(const FInworldEditorClientOptions& Options, TFunction<void(const FString& FirebaseToken)> InCallback);
	void RequestReadyPlayerMeModelData(const FInworldStudioUserCharacterData& CharacterData, TFunction<void(const TArray<uint8>& Data)> InCallback);

	void CancelRequests();

	bool IsRequestInProgress() const;
	const FString& GetError() const;

private:
	TSharedPtr<Inworld::FEditorClient> InworldEditorClient;
};
