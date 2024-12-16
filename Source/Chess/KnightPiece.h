#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "KnightPiece.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API AKnightPiece : public AChessPiece
{
	GENERATED_BODY()
	
public:
	virtual void PrintType() override { UE_LOG(LogTemp, Warning, TEXT("Knight")); };
	virtual void ClickOnPiece();
	virtual void GetAvailableMovement();
};
