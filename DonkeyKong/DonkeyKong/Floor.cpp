#include "Floor.h"


CFloor::CFloor(Float3 pos, Float3 size)
{
	Pos = pos;

	Size = size;
}

void CFloor::Draw(Color color)
{
	Box(Pos, Size).draw(color);
}
