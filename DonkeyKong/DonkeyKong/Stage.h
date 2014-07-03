#pragma once
#include <Siv3D.hpp>
#include "Player.h"
#include "Floor.h"


class Stage
{
private:

public:
	Stage();
	~Stage();

	void Update();
	CFloor *floor;
	CPlayer *player;

};

extern Stage *stage;