#include "Floor.h"


CFloor::CFloor(Float3 pos)
{
	Pos = pos;

	Size = Float3(32, 32, 32);

}

CFloor::~CFloor(){}

void CFloor::Draw()
{
	Box(Pos, Size).draw();
}
