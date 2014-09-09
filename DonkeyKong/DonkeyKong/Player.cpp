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
	Reset();
}

void CPlayer::Reset()
{
	Pos = Float3(-112, 16, 0);

	Velocity = Float3(0, 0, 0);
	Direction = Float3(0, 0, 0);

	Size = Float3(16, 16, 16);

	force = 0;

	State = STATE::NOTE;
	color = Palette::Red;

	UseCount = UseMaxCount;
}

//	
void CPlayer::Move()
{
	Pos += Velocity;

	if (Input::KeyLShift.clicked && State == STATE::NOTE
		|| Input::KeyRShift.clicked && State == STATE::NOTE)
	{
		force = 8;
		State = STATE::JUNP;
	}
	if (Input::KeyRight.pressed)
	{
		Velocity.x = Speed;
		Direction.x = 1;
	}
	else if (Input::KeyLeft.pressed)
	{
		Velocity.x = -Speed;
		Direction.x = -1;
	}
	else
	{
		Velocity.x = 0;
	}
	if (Pos.y < -100)
	{
		Death();
	}


	Velocity.y = -3.8f;

	if (State != STATE::HAMMER)
	{
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

					State = STATE::NOTE;
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

	if (Collision::IsCollisionBox(Pos, Size, stage->hammer->Pos, stage->hammer->Size))
	{
		if (State != STATE::HAMMER)
		{
			State = STATE::HAMMER;
		}
	}
	if (Collision::IsCollisionBox(Pos, Size, stage->reddy->Pos, stage->reddy->Size))
	{
		Reset();
	}

	if (State == STATE::NOTE || State == STATE::HAMMER)
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
void CPlayer::UseHammer()
{
	if (State == STATE::HAMMER)
	{
		UseCount -= 1;
	}
	if (UseCount < 0)
	{
		State = STATE::NOTE;
		UseCount = UseMaxCount;
	}
}
void CPlayer::Death()
{
	Pos = Float3(-112, 16, 0);
}
void CPlayer::Update()
{
	UseHammer();
	Collision();
	Move();
}

void CPlayer::Draw()
{	
	//Box(Pos, Size).draw(color);
	Box(Pos.x, Pos.y + Size.y / 2 + 3, Pos.z, Size.x, Size.y * 1.5f, Size.z).draw(color);
}
