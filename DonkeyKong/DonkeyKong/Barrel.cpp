#include "Barrel.h"


CBarrel::CBarrel(int i)
{
	pos[0] = Float3(-218, 326, 0);
	pos[1] = Float3(0, 260, 0);
	pos[2] = Float3(0, 210, 0);
	pos[3] = Float3(0, 160, 0);

	Pos = pos[i];
	Size = Float3( 8, 32, 0);
	color = Color(0, 0, 0);
}
void CBarrel::Draw()
{
	Cylinder(Pos, Size.x, Size.y).draw();
}
