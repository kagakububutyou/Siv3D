#include <math.h>

#include "Hammer.h"
#include "Stage.h"
#include "Collision.h"

CHammer::CHammer()
{
	Pos = Float3(-176, 178, 0);
	Size = Float3(16, 16, 16);
	color = Color(231, 95, 91);

	UseCount = UseMaxCount;
	
	State = STATE::LIVE;
	IsCollisionPlayer = false;
}
void CHammer::Move()
{
	static float i = 10;
	static float angle = 0;

	
	if (IsCollisionPlayer && stage->player->Direction.x > 0)
	{
		if (angle < 0){ i = 10; }
		if (angle > 90)	{ i = -10; }

		Pos = Float3(stage->player->Pos.x + sin(angle*Pi / 180.0)*Size.x, stage->player->Pos.y + Size.y / 2 + cos(angle*Pi / 180.0)*Size.y, stage->player->Pos.z);
	}
	if (IsCollisionPlayer && stage->player->Direction.x < 0)
	{
		if (angle > 360){ i = -10; }
		if (angle < 270){ i = 10; }
		
		Pos = Float3(stage->player->Pos.x + sin(angle*Pi / 180.0)*Size.x, stage->player->Pos.y + Size.y / 2 + cos(angle*Pi / 180.0)*Size.y, stage->player->Pos.z);
	}
	
	if (UseCount < 0)
	{
		State = STATE::DEATH;
		UseCount = UseMaxCount;
	}
	//*/
	

	if (IsCollisionPlayer)
	{
		angle += i;
		UseCount -= 1;
	}
}
void CHammer::Collision()
{
	if (IsCollisionPlayer) return;

	if (Collision::IsCollisionBox(Pos, Size*1.5f, stage->player->Pos, stage->player->Size))
	{
		IsCollisionPlayer = true;
	}
}
void CHammer::Death()
{
	if (State != STATE::DEATH) return;

	if (State == STATE::DEATH)
	{
		Pos = Float3(-100, -100, -100);
	}
}
void CHammer::Update()
{
	if (State != STATE::DEATH)
	{
		Collision();
		Move();
	}
	Death();
}
void CHammer::Draw()
{
	if (State != STATE::DEATH)
	{
		Box(Pos, Size).draw(color);
	}
}