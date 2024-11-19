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

			if (tileClass)
			{
				AActor* tileToSpawn = UGameplayStatics::BeginDeferredActorSpawnFromClass(this, tileClass.LoadSynchronous(), spawnTransform);

				ATile* tile = Cast<ATile>(tileToSpawn);
				if (tile)
				{
					tile->SetTileInfo(FTileInfo(i, j, 0.0f));
				}

				tileToSpawn->FinishSpawning(spawnTransform);
				tiles.Add(tile);
				tile->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
			}
		}
	}
}