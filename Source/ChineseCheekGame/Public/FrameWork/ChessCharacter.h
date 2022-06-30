// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ChessCharacter.generated.h"

UCLASS()
class CHINESECHEEKGAME_API AChessCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AChessCharacter();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	void MouseWheelPush(float value);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USceneComponent* rootComp;//作为根组件
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* ARMcomp;//相机摇臂
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* CameraComp;//相机

private:
	class AChessPlayerState* cplayerState;
	AChessPlayerState* zjhGetPlayerState();
};
