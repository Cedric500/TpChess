#pragma once

#include "CoreMinimal.h"
#include "ChessPiece.h"
#include "PawnPiece.generated.h"

/**
 *
 */
UCLASS()
class CHESS_API APawnPiece : public AChessPiece
{
	GENERATED_BODY()


public:

	virtual void PrintType() override { UE_LOG(LogTemp, Warning, TEXT("Pawn")); };


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = true))
	bool FirstMove;
};
