#pragma once
// vector::push_back
#include <iostream>
#include "CoreMinimal.h"
#include "Math/IntPoint.h"
#include <vector>
#include "GameFramework/Actor.h"
#include "ChessPiece.generated.h"

UCLASS()
class CHESS_API AChessPiece : public AActor
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	virtual void PrintType() { UE_LOG(LogTemp, Warning, TEXT("BaseClass")); };

public:

	AChessPiece();


	UFUNCTION(BlueprintCallable)
	virtual void ClickOnPiece() {};

	virtual void GetAvailableMovement() {};

	virtual void MovingPiece() {};

	TArray<FInt32Point> PossibleMove;

	int PosI;
	int PosJ;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components", meta = (AllowPrivateAccess = true))
	bool isBlack;



public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

private:

};
