#include "Ladder.h"


CLadder::CLadder(Float3 pos, Float3 size)
{
	Pos = pos;

	Size = size;

	color = Color(0, 235, 219);
}
void CLadder::Update()
{


}
void CLadder::Draw()
{
	Box(Pos, Size).draw(color);
}
