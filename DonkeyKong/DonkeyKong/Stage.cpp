#include "Stage.h"
#include "Player.h"
#include "Floor.h"
#include "Ladder.h"
#include "Barrel.h"
Stage *stage;


Stage::Stage()
{

	//		スマートポインタ宣言の仕方
	player.reset(new CPlayer());
	Map();
}


Stage::~Stage()
{

}
void Stage::Map()
{
	
	const CSVReader map(L"csv/Map.csv");
	const CSVReader lad(L"csv/Ladder.csv");
	const Font font(20);

	if (!map || !lad)
	{
		MessageBox::Show(L"エラー", L"読み込みに失敗しました。");
		return;
	}
	Println(L"csv の行数: ", map.rows - 1);

	Println(L"csv の 1 行目の列数: ", map.columns(1));

	
	// 0 行目、2 列の要素
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
	for (int i = 0; i < 4; i++)
	{
		obj[OBJECT::BARREL].emplace_back(new CBarrel(i));
	}
}
void Stage::Update()
{
	player->Move();

	for (int j = 0, max = OBJECT::ALL; j < max; j++)
	{
		for (auto &i : obj[j])
		{
			i->Draw();
		}
	}

	player->Draw();
}