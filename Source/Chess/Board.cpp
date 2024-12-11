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

				tile->SetPiece(PlaceChessPieces(i, j, spawnTransform));
			}

			tileToSpawn->FinishSpawning(spawnTransform);
			tiles.Add(tile);
			tile->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

		}
	}
}

AChessPiece* ABoard::PlaceChessPieces(int i, int j, FTransform spawnTransform)
{
	AActor* actorPiece = nullptr;

#pragma region PawnPiece
	if (i == 1)
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whitePawnClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if (i == 6)
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkPawnClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion

#pragma region RookPieces
	if ((i == 0 && j == 0) 
		|| (i == 0 && j == 7))
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteRookClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if ((i == 7 && j == 7) 
		|| (i == 7 && j == 0))
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkRookClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion

#pragma region KnightPiece
	if ((i == 0 && j == 1)
		|| (i == 0 && j == 6))
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteKnightClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if ((i == 7 && j == 1)
		|| (i == 7 && j == 6))
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkKnightClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion

#pragma region BishopPiece
	if ((i == 0 && j == 2)
		|| (i == 0 && j == 5))
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteBishopClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if ((i == 7 && j == 2)
		|| (i == 7 && j == 5))
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkBishopClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion

#pragma region QueenPiece
	if (i == 0 && j == 4)
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteQueenClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if (i == 7 && j == 4)
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkQueenClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion

#pragma region KingPiece
	if (i == 0 && j == 3)
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, whiteKingClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
	else if (i == 7 && j == 3)
	{
		actorPiece = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, darkKingClass.LoadSynchronous(), spawnTransform);

		actorPiece->FinishSpawning(spawnTransform);
		actorPiece->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	}
#pragma endregion


	AChessPiece* piece = Cast<AChessPiece>(actorPiece);
	if (piece)
	{
		return piece;
	}

	return nullptr;
}