#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ChessPiece.h"
#include "Tile.generated.h"

class ABoard;

USTRUCT(BlueprintType)
struct FTileInfo
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int x{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int y{};
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int z{};

public:
	FTileInfo() = default;
	FTileInfo(int const a_X, int const a_Y, int const a_Z)
		: x(a_X), y(a_Y), z(a_Z)
	{}
};

UCLASS()
class CHESS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	ATile();

	void SetTileInfo(FTileInfo a_tileInfo) { TileInfo = a_tileInfo; }
	void SetPiece(AChessPiece* piece) { Piece = piece; }

	UFUNCTION(BlueprintCallable)
	FTileInfo GetTileInfo() { return TileInfo; }

	UFUNCTION(BlueprintCallable)
	AChessPiece* GetPiece() { return Piece; }

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	ABoard* BoardRef;

protected:
	virtual void BeginPlay() override;
	


public:	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Config", meta = (AllowPrivateAccess = true))
	FTileInfo TileInfo;

	AChessPiece* Piece;

};
