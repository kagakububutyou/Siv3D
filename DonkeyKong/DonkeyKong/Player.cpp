#include "Player.h"
#include "Collision.h"
#include "Stage.h"
#include "Floor.h"

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

	
	if (Input::KeyUp.clicked && State != STATE::JUNP)
	{
		force = 8.5f;
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
			/*
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				//Pos.y -= force;
				Pos.y += Velocity.y;
				Pos.x += Speed;
				if (Pos.y <= i->Pos.y && Pos.y >= i->Pos.y + i->Size.y)
				{
					if (Pos.x >= i->Pos.x)
					{

					}
				}
				//if (Pos.y >= i->Pos.y - i->Size.y*2 && Pos.y <= i->Pos.y + i->Size.y)
				State = STATE::LIVE;
			}
			//*/
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
				/*
				if (Pos.x >= i->Pos.x)
				{
				Pos.x -= Velocity.x;
				}
				//*/
				if (Pos.y >= i->Pos.y - i->Size.y * 2 && Pos.y <= i->Pos.y + i->Size.y)
				{
					//Pos.x += Velocity.x;
				}
				//*/
				//Velocity.y = 0;
			}
		}
	}
	//	ドラム缶(輸送用)
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
	//Box(Pos.x,Pos.y + Size.y/2,Pos.z, Size.x, Size.y * 2, Size.z).draw(Palette::Blue);
}
