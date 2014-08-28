#include "Ladder.h"
/*
	
	‚Í‚µ‚²

*/

CLadder::CLadder(Float3 pos, Float3 size)
{
	Pos = pos;

	Size = size;

	color = Color(0, 235, 219);
}
void CLadder::Draw()
{
	Box(Pos, Size).draw(color);
}
