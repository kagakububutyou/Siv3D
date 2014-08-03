#include "Bullet.h"
#include  "Stage.h"
#include "Collision.h"

CBullet::CBullet()
{
	Pos = Float3(-136, 348, -5);
	Velocity = Float3(0 , 0, 0);
	Size = Float3(16, 32, 16);
	color = Color(231, 95, 91);
	Speed = -2.5f;
	Gravity = -3.8f;
	CollisionFloor = false;
}
void CBullet::Move()
{
	Pos += Velocity;

	Velocity.y = Gravity;
}
void CBullet::Collision()
{
	for (auto &i : stage->obj[stage->FLOOR])
	{
		if (!Collision::IsCollisionBox(Pos, Size / 2, i->Pos, i->Size))
		{
			Velocity.x = 0;

			if (Pos.y < posY - i->Size.y)
			{
				CollisionFloor = false;
			}
		}
	}
	//	°‚É“–‚½‚Á‚Ä‚éŽž
	for (auto &i : stage->obj[stage->FLOOR])
	{
		if (Collision::IsCollisionBox(Pos, Size / 2, i->Pos, i->Size))
		{
			Pos.y -= Velocity.y;
			if (CollisionFloor == false)
			{
				Speed = -1 * Speed;
				CollisionFloor = true;
			}
			Velocity.x = Speed;
			posY = Pos.y;
		}
	}
}
void CBullet::Update()
{
	Collision();
	Move();
}
void CBullet::Draw()
{
	static double i = 0;
	i++;
	Cylinder(Size.x / 2, Size.y, Quaternion::RollPitchYaw(0, Pi / 180 * 90, 0)).rotate(Vec3(0, 0, Pi / 180 * i)).translate(Pos).draw(color);
}