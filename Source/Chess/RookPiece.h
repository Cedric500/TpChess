#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "RookPiece.generated.h"

/**
 * 
 */
UCLASS()
class CHESS_API ARookPiece : public AChessPiece
{
	GENERATED_BODY()
	

public:
	virtual void PrintType() override { UE_LOG(LogTemp, Warning, TEXT("Rook")); };
	virtual void ClickOnPiece();
	virtual void GetAvailableMovement();
};
