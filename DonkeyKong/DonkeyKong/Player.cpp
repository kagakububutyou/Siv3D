#include "Player.h"
#include "Collision.h"
#include "Stage.h"
#include "Floor.h"

const float CPlayer::Speed = 5;

CPlayer::CPlayer()
{
	Pos = Float3(-112, 16, 0);

	Velocity = Float3(0, 0, 0);

	Size = Float3(16,32,16);

	force = 0;

	State = STATE::LIVE;

	color = Palette::Red;
}

void CPlayer::Move()
{
	Pos += Velocity;

	
	if (Input::KeyUp.clicked && State != STATE::JUNP)
	{
		force = 15;
		State = STATE::JUNP;
	}

	if (State == STATE::JUNP)
	{
		force--;
		Pos.y += force;
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				State = STATE::LIVE;
				Pos.y -= force;
				Pos.x -= 1;
			}
		}
			
	}
	if (Input::KeyRight.pressed)
	{
		Velocity.x = Speed;
	}
	else if (Input::KeyLeft.pressed)
	{
		Velocity.x = -Speed;
	}
	else
	{
		Velocity.x = 0;
	}

	Velocity.y = -3.8f;
}
void CPlayer::Collision()
{
	//	床に当たってない時
	for (auto &i : stage->obj[stage->FLOOR])
	{
		if (!Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{

		}
	}
	//	床に当たってる時
	for (auto &i : stage->obj[stage->FLOOR])
	{
		if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{
			Pos.y -= Velocity.y;
			//Velocity.y = 0;
		}
	}
	for (auto &i : stage->obj[stage->DRUM])
	{
		if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{
			if (Pos.x > i->Pos.x)
			{
				Pos.x += Speed;
			}
			
		}
	}
}
void CPlayer::Update()
{
	Collision();
	Move();
}

void CPlayer::Draw()
{
	Box(Pos, Size).draw(color);
}
