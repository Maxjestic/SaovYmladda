// Copyright © 2025 Maksymilian Kafka. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/SYCharacterBase.h"
#include "Interfaces/PlayerInputReceiverInterface.h"
#include "SYPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS( Abstract, Blueprintable )
class SAOVYMLADDA_API ASYPlayerCharacter : public ASYCharacterBase, public IPlayerInputReceiverInterface
{
	GENERATED_BODY()

public:
	//~ Begin IPlayerInputReceiver Interface
	virtual void RequestDodge_Implementation() override;
	virtual void RequestJump_Implementation() override;
	virtual void RequestLook_Implementation(const FInputActionValue& Value) override;
	virtual void RequestMove_Implementation(const FInputActionValue& Value) override;
	//~ End IPlayerInputReceiver Interface
};
