// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "ChessPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class CHINESECHEEKGAME_API AChessPlayerState : public APlayerState
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MouseAttrs")
		float ARMSpeed = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MouseAttrs")
		TSubclassOf<	class UUserWidget> MouseStyle;

};
