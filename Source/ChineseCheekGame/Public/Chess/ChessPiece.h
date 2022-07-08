// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessPiece.generated.h"

UCLASS()
class CHINESECHEEKGAME_API AChessPiece : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChessPiece();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* rootComp;//作为根组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* chessMesh;//棋子网格体
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UTextRenderComponent* textComp;//文字定位

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterailsForChessTextInfo")
		class UMaterialInstance* matForRedChess;//红色材质
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterailsForChessTextInfo")
		class UMaterialInstance* matForBlueChess;//蓝色材质

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterailsForChessClick")
		class UMaterialInstance* matForWoodDefault;//wood的默认材质
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterailsForChessClick")
		class UMaterialInstance* matForWoodClick;//wood的默认材质
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterailsForChessClick")
		class UMaterialInstance* matForRoundDefault;//花边的默认材质
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MaterailsForChessClick")
		class UMaterialInstance* matForRoundClick;//花边的默认材质

	void SetTextInfo(FString inStr);//设置文字信息
	void SetTextColor(bool isRedChess);//设置棋子颜色,是否为红色棋子

	void DefaultMat();//鼠标松开是换回原来的材质
	void ClickMat();//鼠标点击时换材质

	bool isAutoMove = false;
	bool IsCanDeath = false;
	FVector targetLocation, moveDirection, startLocation;
	float maxMoveTime = 0.3f, moveTime, moveDistance, moveVelocity, deathTime;

	void TickMoveSelf(float deltaTime);

	void MoveSelf(FVector inLocation);
	void DeletSelf();
};
