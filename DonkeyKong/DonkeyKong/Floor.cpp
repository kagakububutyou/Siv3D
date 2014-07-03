#include "Floor.h"


CFloor::CFloor()
{
	Pos = Float3(0, -128, 0);

	Size = Float3(128, 32, 32);

}

CFloor::~CFloor()
{
}

void CFloor::Draw()
{
	Box(Pos, Size).draw();
}
