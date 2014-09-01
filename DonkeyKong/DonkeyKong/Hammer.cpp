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
	if (IsCollisionPlayer && stage->player->Velocity.x > 0)
	{
		Pos = Float3(stage->player->Pos.x+Size.x,stage->player->Pos.y+Size.y/2,stage->player->Pos.z);
	}
	if (IsCollisionPlayer && stage->player->Velocity.x < 0)
	{
		Pos = Float3(stage->player->Pos.x - Size.x, stage->player->Pos.y + Size.y / 2, stage->player->Pos.z);
	}
	if (IsCollisionPlayer)
	{
		UseCount -= 1;
	}
	if (UseCount < 0)
	{
		State = STATE::DEATH;
		UseCount = UseMaxCount;
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