// vector::push_back
#include <iostream>
#include "RookPiece.h"

#include <vector>

ARookPiece::ARookPiece()
{

	for (int i = 1; i <= 7; i++)
	{
		PossibleMove.Add({ 0,i });
		PossibleMove.Add({ i,0 });
		PossibleMove.Add({ 0,-i });
		PossibleMove.Add({ -i,0 });
	}
}