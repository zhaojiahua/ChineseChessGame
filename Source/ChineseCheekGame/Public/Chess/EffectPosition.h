// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EffectPosition.generated.h"

UCLASS()
class CHINESECHEEKGAME_API AEffectPosition : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEffectPosition();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* rootComp;//作为根组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* moveMesh;//可移动网格
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* eatMesh;//可吃子网格

private:
	int32 row = 0, col = 0;
public:
	void SetRowCol(int32 inRow,int32 inCol);
	int32 GetRow();
	int32 GetCol();

	class AChessPiece* chessPiece = nullptr;//该位置是否有棋子
	void SetChessToThisPos(class AChessPiece* inChessPiece);
	bool HasChessActor();//判断此位置是否有棋子
	class AChessPiece* GetChessFromThisPos();

	void HideMesh();
	void ShowMoveMesh();
	void ShowEatMesh();
};
