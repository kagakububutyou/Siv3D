#include "Barrel.h"


CBarrel::CBarrel(Float3 pos)
{
	Pos = pos;
	Size = Float3( 8, 32, 16);
	color = Color(231, 95, 91);
}
void CBarrel::Update()
{


}
void CBarrel::Draw()
{
	Cylinder(Pos, Size.x, Size.y).draw(color);
}
