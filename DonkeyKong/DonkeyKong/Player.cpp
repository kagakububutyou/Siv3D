#include "Player.h"
#include "Collision.h"
#include "Stage.h"
#include "Floor.h"

const float CPlayer::Speed = 5;

CPlayer::CPlayer()
{
	Pos = Float3(-112, 16, 0);

	Velocity = Float3(0, 0, 0);

	Size = Float3(16,16,16);

	force = 0;

	State = STATE::LIVE;

	color = Palette::Red;
}

void CPlayer::Move()
{
	Pos += Velocity;

	
	if (Input::KeyUp.clicked && State != STATE::JUNP)
	{
		force = 13;
		State = STATE::JUNP;
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
	//	ƒWƒƒƒ“ƒv’†
	if (State == STATE::JUNP)
	{
		force--;
		Pos.y += force;
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				Pos.y -= force;
				if (Pos.x > i->Pos.x)
				{
					Pos.x += i->Size.x;
				}
				State = STATE::LIVE;
			}
		}
	}

	//	°‚É“–‚½‚Á‚Ä‚È‚¢Žž
	for (auto &i : stage->obj[stage->FLOOR])
	{
		if (!Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{

		}
	}
	//	°‚É“–‚½‚Á‚Ä‚éŽž
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
	Box(Pos.x,Pos.y + Size.y/2,Pos.z, Size.x, Size.y * 2, Size.z).draw(Palette::Blue);
}
