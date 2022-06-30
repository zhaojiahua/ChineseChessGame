// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ChessPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class CHINESECHEEKGAME_API AChessPlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AChessPlayerController();

protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

	void MouseLookUD(float value);
	void MouseLookLR(float value);

	void MouseWheelPush(float value);

	void MousePressed();
	void MouseReleased();

public:
	virtual void Tick(float DeltaTime) override;

private:
	class AChessCharacter* cPlayer;
	class AChessRule* chessRule;
	class AChessBoard* chessBoard;

public:
	UPROPERTY(BlueprintReadOnly,Category="MouseAttrs")
	bool bIsMousePressed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWorks")
		TSubclassOf<class AChessRule> chessRule_BP;//ChessRule规则类蓝图

	void MouseDownClick();

};
