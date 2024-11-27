#include "Board.h"
#include "Kismet/GameplayStatics.h"

ABoard::ABoard()
{
	PrimaryActorTick.bCanEverTick = false;
}

void ABoard::BeginPlay()
{
	Super::BeginPlay();
}

void ABoard::BuildBoard(const int a_Rows, const int a_Columns)
{
	if (tiles.Num() != 0) return;

	size.X = a_Rows;
	size.Y = a_Columns;

	for (auto i{ 0 }; i < a_Rows; i++)
	{
		for (auto j{ 0 }; j < a_Columns; j++)
		{
			const float sectorSize = 100.f;

			// spawn transform where all tiles will spawn
			FVector spawnLocation = FVector(
				static_cast<float>(j) * sectorSize,
				static_cast<float>(i) * sectorSize,
				0.0f);

			FTransform spawnTransform;
			spawnTransform.SetLocation(spawnLocation);

			AActor* tileToSpawn = nullptr;

			if ((i + j) % 2 && blackTileClass)
			{
				tileToSpawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, blackTileClass.LoadSynchronous(), spawnTransform);
			}
			else if (whiteTileClass)
			{
				tileToSpawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteTileClass.LoadSynchronous(), spawnTransform);
			}

			ATile* tile = Cast<ATile>(tileToSpawn);
			if (tile)
			{
				tile->SetTileInfo(FTileInfo(i, j, 0.0f));

				PlaceChessPieces(i, j, spawnTransform);

				//tile->SetPiece(piece);
			}

			tileToSpawn->FinishSpawning(spawnTransform);
			tiles.Add(tile);
			tile->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		}
	}
}

void ABoard::PlaceChessPieces(int i, int j, FTransform spawnTransform)
{
#pragma region PawnPiece
	if (i == 1)
	{
		AActor* whitePawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whitePawnClass.LoadSynchronous(), spawnTransform);

		whitePawn->FinishSpawning(spawnTransform);
		whitePawn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if (i == 6)
	{
		AActor* darkPawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkPawnClass.LoadSynchronous(), spawnTransform);

		darkPawn->FinishSpawning(spawnTransform);
		darkPawn->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion

#pragma region RookPieces
	if ((i == 0 && j == 0) 
		|| (i == 0 && j == 7))
	{
		AActor* whiteRook = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteRookClass.LoadSynchronous(), spawnTransform);

		whiteRook->FinishSpawning(spawnTransform);
		whiteRook->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if ((i == 7 && j == 7) 
		|| (i == 7 && j == 0))
	{
		AActor* darkRook = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkRookClass.LoadSynchronous(), spawnTransform);

		darkRook->FinishSpawning(spawnTransform);
		darkRook->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion
}