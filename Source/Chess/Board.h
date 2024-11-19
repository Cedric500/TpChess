// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.h"
#include "Board.generated.h"



UCLASS()
class CHESS_API ABoard : public AActor
{
	GENERATED_BODY()
	
public:
	ABoard();

	UFUNCTION(BlueprintCallable)
	void BuildBoard(const int a_X, const int a_Y);

protected:
	virtual void BeginPlay() override;


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	FVector2D size;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<TObjectPtr<ATile>> tiles;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	TSoftClassPtr<ATile> tileClass;

};
