// Fill out your copyright notice in the Description page of Project Settings.


#include "FrameWork/ChessPlayerState.h"
#include "Kismet/GameplayStatics.h"
#include "Components/AudioComponent.h"

AChessPlayerState::AChessPlayerState()
{
}

void AChessPlayerState::BeginPlay()
{
	Super::BeginPlay();
	if (BGMMusic)
	{
		BGMComp = UGameplayStatics::CreateSound2D(this, BGMMusic);
		BGMComp->Play();
		SetBGMVaule(0.3);
	}
}

void AChessPlayerState::SetBGMVaule(float inValue)
{
	BGMComp->SetVolumeMultiplier(inValue);
}
