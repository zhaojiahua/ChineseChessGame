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
		AChessPlayerState();
	virtual void BeginPlay() override;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MouseAttrs")
		float ARMSpeed = 2.f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MouseAttrs")
		TSubclassOf<	class UUserWidget> MouseStyle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Music")
		class USoundBase* BGMMusic;

	UFUNCTION(BlueprintCallable, Category = "zjhAddFuns")
		void SetBGMVaule(float inValue = 0.3);

private:
	class UAudioComponent* BGMComp;//创建一个组建负责监听
};
