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
}


CPlayer::~CPlayer()
{
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
		for (auto &i : stage->floor)
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				State = STATE::LIVE;
				Pos.y -= force;
				Pos.x -= 1;
			}
		}
			
	}
	/*
	if (Input::KeyUp.pressed)
	{
		Velocity.y = Speed;
	}
	else if (Input::KeyDown.pressed)
	{
		Velocity.y = -Speed;
	}
	else
	{
		Velocity.y = 0;
	}
	//*/

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


	//	°‚É“–‚½‚Á‚Ä‚È‚¢Žž
	for (auto &i : stage->floor)
	{
		if (!Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{
			
		}
	}
	//	°‚É“–‚½‚Á‚Ä‚éŽž
	for (auto &i : stage->floor)
	{
		if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{			
			Pos.y -= Velocity.y;
			//Velocity.y = 0;
		}
	}
}
void CPlayer::Draw()
{
	Box(Pos, Size).draw(Palette::Red);
}
