#include "Stage.h"
#include "Player.h"
#include "Floor.h"

Stage *stage;

Stage::Stage()
{
	//		スマートポインタ宣言の仕方
	player.reset(new CPlayer());
	floor.reset(new CFloor(Float3(0,-200,0)));

}


Stage::~Stage()
{

}

void Stage::Update()
{
	player->Move();

	floor->Draw();
	player->Draw();
}
