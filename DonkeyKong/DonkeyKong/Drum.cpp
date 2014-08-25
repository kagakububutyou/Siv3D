#include "Drum.h"
/*
	
	ƒhƒ‰ƒ€ŠÊ(—A‘——p)

*/

CDrum::CDrum()
{
	Pos = Float3(-160, 24, 0);
	Size = Float3(32, 32, 16);
	color = Color(0, 88, 248);
}
void CDrum::Update()
{

}
void CDrum::Draw()
{
	Cylinder(Pos, Size.x / 2, Size.y).draw(color);
}