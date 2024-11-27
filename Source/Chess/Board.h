#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"
#include "ChessPiece.h"
#include "Board.generated.h"



UCLASS()
class CHESS_API ABoard : public AActor
{
	GENERATED_BODY()

public:
	ABoard();

	UFUNCTION(BlueprintCallable)
	void BuildBoard(const int a_X, const int a_Y);

private:
	void PlaceChessPieces(int i, int j, FTransform spawnTransform);
protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector2D size;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<ATile>> tiles;

#pragma region Tiles
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<ATile> whiteTileClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<ATile> blackTileClass;
#pragma endregion

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AChessPiece> whitePawnClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AChessPiece> whiteRookClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AChessPiece> darkPawnClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<AChessPiece> darkRookClass;
};
