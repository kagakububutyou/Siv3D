#include "Bullet.h"

Cylinder* cylinder;
CBullet::CBullet()
{
	Pos = Float3(-136, 348, -5);
	Velocity = Float3(0, 0, 0);
	Size = Float3(16, 32, 16);
	color = Color(231, 95, 91);
	cylinder = new Cylinder(Pos, Size.x / 2, Size.y);
}
void CBullet::Update()
{

}
void CBullet::Draw()
{
	static double i = 0;
	i++;
	Cylinder(Size.x / 2, Size.y, Quaternion::RollPitchYaw(0, Pi / 180 * 90, 0)).rotate(Vec3(0, 0, i)).translate(Pos).draw(color);
		/*
		cylinder->rotate(Float3(Radians(i), 0, 0));
		cylinder->translate(Pos);
		cylinder->scale(Size.x / 2);
		cylinder->draw(color);*/
	
	
}