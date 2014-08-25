#include "Barrel.h"
/*

		’M	

*/

CBarrel::CBarrel(Float3 pos)
{
	Pos = pos;
	Size = Float3( 16, 32, 16);
	color = Color(231, 95, 91);
}
void CBarrel::Update()
{


}
void CBarrel::Draw()
{
	Cylinder(Pos, Size.x / 2, Size.y).draw(color);
}
