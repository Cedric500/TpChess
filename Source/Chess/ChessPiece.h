#pragma once

#include "CoreMinimal.h"
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

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	bool isBlack;

public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components", meta = (AllowPrivateAccess = true))
	TObjectPtr<UStaticMeshComponent> StaticMeshComponent;

private:

};
