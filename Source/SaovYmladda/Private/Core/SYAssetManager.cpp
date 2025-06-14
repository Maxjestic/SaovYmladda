// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.


#include "Core/SYAssetManager.h"

#include "Core/FSYGameplayTags.h"

USYAssetManager& USYAssetManager::Get()
{
	check( GEngine );

	USYAssetManager* SYAssetManager = Cast<USYAssetManager>( GEngine->AssetManager );
	return *SYAssetManager;
}

void USYAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	FSYGameplayTags::InitializeNativeGameplayTags();
}
