#include "Player.h"


Player::Player()
{
	Pos.x = 0;
	Pos.y = 0;
	Pos.z = 0;

	Vec.x = 0;
	Vec.y = 0;

	Speed.x = 0.05f;
	Speed.y = 0.05f;

	Size.x = 32;
	Size.y = 32;
}


Player::~Player()
{
}

void Player::Move()
{
	if (Input::KeyUp.pressed)
	{
		Vec.y = +Speed.y;
	}
	else if (Input::KeyDown.pressed)
	{
		Vec.y = -Speed.y;
	}
	else
	{
		Vec.y = 0;
	}

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

	Pos.y += Vec.y;
	Pos.x += Vec.x;

}

void Player::Drwa()
{
	//RectF(Pos, Size).draw();
	Box(Pos,1).draw();
}
