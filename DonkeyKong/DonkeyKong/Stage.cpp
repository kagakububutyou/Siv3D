#include "Stage.h"

Stage *stage;

Stage::Stage()
{
	player = new CPlayer();
	floor = new CFloor();
}


Stage::~Stage()
{
	delete player;
	delete floor;
}

void Stage::Update()
{
	player->Move();

	floor->Draw();
	player->Draw();
}
