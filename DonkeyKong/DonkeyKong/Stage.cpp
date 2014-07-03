#include "Stage.h"



Stage::Stage()
{
	player = new Player();
}


Stage::~Stage()
{
	delete player;
}

void Stage::Update()
{
	player->Move();

	player->Drwa();
}
