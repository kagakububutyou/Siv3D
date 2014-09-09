#include "Player.h"
#include "Collision.h"
#include "Stage.h"
#include "Floor.h"

/*

		�v���C���[

*/

const float CPlayer::Speed = 2.5f;

CPlayer::CPlayer()
{
	Reset();

	Text.reset(new Font(20, Typeface::Default));
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
		|| Input::KeyRShift.clicked && State == STATE::NOTE
		 || Input::KeySpace.clicked && State == STATE::NOTE)
	{
		force = 8;
		State = STATE::JUNP;
	}
	if (Input::KeyRight.pressed)
	{
		Velocity.x = Speed;
		Direction.x = 1;
		SoundAsset(L"Walk").play();
	}
	else if (Input::KeyLeft.pressed)
	{
		Velocity.x = -Speed;
		Direction.x = -1;
		SoundAsset(L"Walk").play();
	}
	else
	{
		Velocity.x = 0;
		SoundAsset(L"Walk").stop();
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
					SoundAsset(L"Walk").play();
				}
				else if (Input::KeyDown.pressed)
				{
					Velocity.y = 0;
					Pos.y -= Speed;
					SoundAsset(L"Walk").play();
				}
				else if (Input::KeyUp.code && Input::KeyDown.code)
				{
					Velocity.y = 0;
				}
				else if (State == STATE::JUNP)
				{
					Velocity.y = -3.8f;
				}
			}
		}
	}
	if (State == STATE::HAMMER)
	{
		SoundAsset(L"BGM").stop();
		SoundAsset(L"Hammer").play();
	}
	if (State != STATE::HAMMER)
	{
		SoundAsset(L"Hammer").stop();
		SoundAsset(L"BGM").play();
	}
}
void CPlayer::Collision()
{
	//	�W�����v��
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
		State = STATE::HAMMER;
	}
	if (Collision::IsCollisionBox(Pos, Size, stage->hammer->Pos, stage->hammer->Size))
	{
		if (State == STATE::HAMMER)
		{
			State = STATE::NOTE;
		}
	}
	if (Collision::IsCollisionBox(Pos, Size, stage->enemy->Pos, stage->enemy->Size))
	{
		Death();
	}
	if (Collision::IsCollisionBox(Pos, Size, stage->reddy->Pos, stage->reddy->Size))
	{
		Reset();
	}

	if (State == STATE::NOTE || State == STATE::HAMMER)
	{
		//	���ɓ������ĂȂ���
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (!Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				//State = STATE::JUNP;
			}
		}
		//	���ɓ������Ă鎞
		for (auto &i : stage->obj[stage->FLOOR])
		{
			if (Collision::IsCollisionBox(Pos, Size, i->Pos, i->Size))
			{
				Pos.y -= Velocity.y;
			}
		}
	}
	//	�h������(�A���p)
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
		//UseCount = UseMaxCount;
	}
}
void CPlayer::Death()
{
	//Reset();

	Pos = Float3(-112, 16, 0);
	State = STATE::NOTE;

	//UseCount = -1;
}
void CPlayer::Update()
{
	stage->hammer->Update();

	Collision();
	UseHammer();
	Move();
}

void CPlayer::Draw()
{	
	Box(Pos, Size).draw(color);
	Box(Pos.x, Pos.y + Size.y / 2, Pos.z, Size.x, Size.y * 1.5f, Size.z).draw(color);

	//Box(Float3(Pos.x, Pos.y + Size.y / 2 + 3, Pos.z), Float3(Size.x, Size.y * 1.5f, Size.z)).draw(color);
}
