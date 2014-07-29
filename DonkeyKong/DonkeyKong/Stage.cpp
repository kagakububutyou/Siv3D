#include "Stage.h"
#include "Player.h"
#include "Floor.h"
#include "Ladder.h"
#include "Barrel.h"
#include "Enemy.h"
#include "Drum.h"
Stage *stage;


Stage::Stage()
{

	//		スマートポインタ宣言の仕方
	player.reset(new CPlayer());
	enemy.reset(new CEnemy());
	Map();
}


Stage::~Stage()
{

}
void Stage::Map()
{
	const CSVReader map	(L"csv/Map.csv");
	const CSVReader lad(L"csv/Ladder.csv");
	const CSVReader bar(L"csv/Barrel.csv");

	if (!map || !lad || !bar)
	{
		MessageBox::Show(L"エラー", L"読み込みに失敗しました。");
		return;
	}	

	int MapWidth = map.columns(1);
	int MapHeight = map.rows;
	Float3 MapSize = map.get<Float3>(0, 0);
	for (int j = 1; j < MapHeight; j++)
	{
		for (int i = 0; i < MapWidth; i++)
		{
			obj[OBJECT::FLOOR].emplace_back(new CFloor(Float3(map.get<Float3>(j, i)), MapSize));
		}
	}
	MapWidth = lad.columns(1);
	
	for (int i = 0; i < MapWidth; i++)
	{
		Item item;
		item.Pos = lad.get<Float3>(1, i);
		item.Size = lad.get<Float3>(2, i);
		obj[OBJECT::LADDER].emplace_back(new CLadder(item.Pos, item.Size));
	}
	MapWidth = bar.columns(1);
	for (int i = 0; i < MapWidth; i++)
	{
		obj[OBJECT::BARREL].emplace_back(new CBarrel(Float3(bar.get<Float3>(1,i))));
	}
	obj[OBJECT::DRUM].emplace_back(new CDrum());
}
void Stage::Update()
{
	player->Update();	
}
void Stage::Draw()
{
	for (int j = 0, max = OBJECT::ALL; j < max; j++)
	{
		for (auto &i : obj[j])
		{
			i->Draw();
		}
	}

	player->Draw();
	enemy->Draw();
}
void Stage::GameMain()
{
	Update();
	Draw();
}