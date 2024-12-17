#include "PawnPiece.h"

void APawnPiece::GetAvailableMovement()
{

}

void APawnPiece::MovingPiece()
{
	if (FirstMove)
	{
		FirstMove = false;
	}
}

void APawnPiece::ClickOnPiece()
{
	GetAvailableMovement();
	MovingPiece();
}