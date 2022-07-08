// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "FrameWork/ChessRule.h"
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

	class AAIMoveGenerator* cMove;
	class ASearchMoveEngine* searchEngine;

public:
	UPROPERTY(BlueprintReadOnly,Category="MouseAttrs")
	bool bIsMousePressed = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FrameWorks")
		TSubclassOf<class AChessRule> chessRule_BP;//ChessRule规则类蓝图

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TSubclassOf<class AAIMoveGenerator> cMoveGen_BP;//AI类蓝图

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		TSubclassOf<class ASearchMoveEngine> searchEngine_BP;//AI类蓝图

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
		float moveIntervalTime = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AI")
		bool isRedMove = true;

	void MouseDownClick();

	void ValidMoveChess(FChessMovePoint playerMovePoint);//合法的走法移动棋子

	void AIMove();

private:
	float tempMoveTime = 0;
	bool isCanMoving = false;	//是否移动中
};
