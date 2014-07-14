#include "Stage.h"
#include "Player.h"
#include "Floor.h"

Stage *stage;


Stage::Stage()
{
	const CSVReader csv(L"Map.csv");

	if (!csv)
	{
		MessageBox::Show(L"エラー", L"Map.csv の読み込みに失敗しました。");
		return;
	}
	Println(L"CSV の行数: ", csv.rows);

	Println(L"CSV の 0 行目の列数: ", csv.columns(0));

	//		スマートポインタ宣言の仕方
	player.reset(new CPlayer());
	//floor.reset(new CFloor(Float3(0,-200,0)));
	// 0 行目、0 列の要素
	const unsigned itemCount = csv.get<unsigned>(0, 0);

	for (unsigned i = 0; i < itemCount; i++)
	{
		Item item;
		item.pos = csv.get<Float3>(1, i);
		items.push_back(item);
	}

	for (auto  &j : items)
	{
		floor.emplace_back(new CFloor(Float3(j.pos)));
	}	
}


Stage::~Stage()
{

}

void Stage::Update()
{
	player->Move();

	for (auto &i : floor)
	{
		i->Draw();
	}
	player->Draw();
}