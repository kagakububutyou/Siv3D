#include "Drum.h"


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
	//Box(Pos, Size).draw(color);
	Cylinder(Pos, Size.x / 2, Size.y).draw(color);
}