#include "Player.h"
#include "Collision.h"
#include "Stage.h"
#include "Floor.h"

CPlayer::CPlayer()
{
	Pos = Float3(0, 0, 0);

	Vec.x = 0;
	Vec.y = 0;

	Speed.x = 1;
	Speed.y = 1;

	Size = Float3(32,32,32);
}


CPlayer::~CPlayer()
{
}

void CPlayer::Move()
{
	Pos.y += Vec.y;
	Pos.x += Vec.x;


	if (Input::KeyRight.pressed)
	{
		Vec.x = +Speed.x;
	}
	else if (Input::KeyLeft.pressed)
	{
		Vec.x = -Speed.x;
	}
	else
	{
		Vec.x = 0;
	}

	if (!Collision::IsCollisionBox(Pos, Size, stage->floor->Pos, stage->floor->Size))
	{
		Vec.y = -3.8f;
	}
	if (Collision::IsCollisionBox(Pos, Size, stage->floor->Pos, stage->floor->Size))
	{
		Vec.y = 0;
	}



}

void CPlayer::Draw()
{
	
	Box(Pos,Size).draw();
}
