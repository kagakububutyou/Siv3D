#pragma once
#include <Siv3D.hpp>

#include "Player.h"
class Stage
{
private:

	Player *player;

public:
	Stage();
	~Stage();

	void Update();
};

