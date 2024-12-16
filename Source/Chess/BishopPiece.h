// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "BishopPiece.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API ABishopPiece : public AChessPiece
{
	GENERATED_BODY()
	
public:
	virtual void PrintType() override { UE_LOG(LogTemp, Warning, TEXT("Bishop")); };
	virtual void ClickOnPiece();
	virtual void GetAvailableMovement();
};
