#include "Player.h"
#include "Collision.h"
#include "Stage.h"
#include "Floor.h"

/*

		プレイヤー

*/

const float CPlayer::Speed = 2.5f;

CPlayer::CPlayer()
{
	Pos = Float3(-112, 16, 0);

	Velocity = Float3(0, 0, 0);

	Size = Float3(16,16,16);

	force = 0;

	State = STATE::LIVE;

	color = Palette::Red;
}

//	
void CPlayer::Move()
{
	Pos += Velocity;

	if (Input::KeyLShift.clicked && State != STATE::JUNP
		|| Input::KeyRShift.clicked && State != STATE::JUNP)
	{
		force = 8;
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

	for (auto &i : stage->obj[stage->LADDER])
	{
		if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
		{
			if (Input::KeyUp.pressed)
			{
				Velocity.y = 0;
				Pos.y += Speed;
			}
			if (Input::KeyDown.pressed)
			{
				Velocity.y = 0;
				Pos.y -= Speed;
			}
			if (Input::KeyUp.code && Input::KeyDown.code)
			{
				Velocity.y = 0;
			}
			if (State == STATE::JUNP)
			{
				Velocity.y = -3.8f;
			}
		}
	}
}
void CPlayer::Collision()
{
	//	ジャンプ中
	if (State == STATE::JUNP)
	{
		force -= 0.25f;
		Pos.y += force;
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (Pos.x >= i->Pos.x)
			{
				if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
				{
					Pos.x -= Velocity.x;
				}
			}
			else if (Pos.x <= i->Pos.x)
			{
				if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
				{
					Pos.x += Velocity.x;
				}
			}
		}
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (Pos.y >= i->Pos.y)
			{
				if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
				{
					Pos.y -= Velocity.y;

					State = STATE::LIVE;
				}
			}
			else if (Pos.y <= i->Pos.y + i->Size.y)
			{
				if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
				{
					Pos.y += Velocity.y;
				}
			}
		}
	}

	if (State == STATE::LIVE)
	{
		//	床に当たってない時
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (!Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				//State = STATE::JUNP;
			}
		}
		//	床に当たってる時
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				Pos.y -= Velocity.y;
			}
		}
	}
	//	ドラム缶(輸送用)
	for (auto &i : stage->obj[stage->DRUM])
	{
		if (Pos.x >= i->Pos.x)
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{			
				Pos.x += Speed;
			}
		}
		if (Pos.x <= i->Pos.x)
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				Pos.x -= Speed;
			}
		}
	}
}
void CPlayer::Death()
{
	Pos = Float3(-112, 16, 0);
}
void CPlayer::Update()
{
	Collision();
	Move();
}

void CPlayer::Draw()
{	
	//Box(Pos, Size).draw(color);
	Box(Pos.x,Pos.y + Size.y/2+3,Pos.z, Size.x, Size.y * 1.5f, Size.z).draw(Palette::Blue);
}
