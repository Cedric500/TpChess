// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "QueenPiece.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AQueenPiece : public AChessPiece
{
	GENERATED_BODY()

public:
	virtual void PrintType() override { UE_LOG(LogTemp, Warning, TEXT("Queen")); };
	virtual void ClickOnPiece();
	virtual void GetAvailableMovement();
};
