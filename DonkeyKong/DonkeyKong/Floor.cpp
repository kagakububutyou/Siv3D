#include "Floor.h"


CFloor::CFloor(Float3 pos, Float3 size)
{
	Pos = pos;

	Size = size;

}

CFloor::~CFloor(){}

void CFloor::Draw()
{
	Box(Pos, Size).draw();
}
