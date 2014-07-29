#include "Floor.h"


CFloor::CFloor(Float3 pos, Float3 size)
{
	Pos = pos;
	Size = size;
	color = Color(231, 0, 91);
}
void CFloor::Update()
{

}
void CFloor::Draw()
{
	Box(Pos, Size).draw(color);
}
