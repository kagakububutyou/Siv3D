#include "Hammer.h"
#include "Stage.h"
#include "Collision.h"

CHammer::CHammer()
{
	Pos = Float3(-176, 178, 0);
	Size = Float3(16, 16, 16);
	color = Color(231, 95, 91);

	IsCollisionPlayer = false;
}
void CHammer::Move()
{
	if (IsCollisionPlayer && stage->player->Velocity.x >= 0)
	{
		Pos = Float3(stage->player->Pos.x+Size.x,stage->player->Pos.y+Size.y/2,stage->player->Pos.z);
	}
	else if (IsCollisionPlayer && stage->player->Velocity.x < 0)
	{
		Pos = Float3(stage->player->Pos.x - Size.x, stage->player->Pos.y + Size.y / 2, stage->player->Pos.z);
	}
}
void CHammer::Collision()
{
	if (Collision::IsCollisionBox(Pos, Size, stage->player->Pos, stage->player->Size))
	{
		IsCollisionPlayer = true;
	}
}
void CHammer::Update()
{
	Collision();
	Move();
}
void CHammer::Draw()
{
	Box(Pos, Size).draw(color);
}