#include "Stage.h"
#include "Player.h"
#include "Floor.h"

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
	
	const CSVReader csv(L"Map.csv");
	const Font font(20);

	if (!csv)
	{
		MessageBox::Show(L"エラー", L"Map.txt の読み込みに失敗しました。");
		return;
	}
	Println(L"csv の行数: ", csv.rows - 1);

	Println(L"csv の 1 行目の列数: ", csv.columns(1));

	
	// 0 行目、1 列の要素
	const int MapX = csv.get<int>(0, 2);
	const int MapY = csv.rows ;
	const int MapSize = csv.get<int>(0, 0);
	for (int j = 1; j < MapY; j++)
	{
		for (int i = 0; i < MapX; i++)
		{
			floor.emplace_back(new CFloor(Float3(csv.get<Float3>(j, i)), Float3(MapSize, MapSize, MapSize)));
		}
	}
	//*/

	/*
	const int MapWidth = 30;
	const int MapHeight = 1;
	const int MapSize = 16;
	for (int j = 0; j < MapHeight; j++)
	{
		for (int i = 0; i < MapWidth; i++)
		{
			floor.emplace_back(new CFloor(Float3(MapSize*(MapWidth/2 - i),MapSize * j + (1+i),0), Float3(MapSize, MapSize, MapSize)));
		}
	}
	//*/


}
void Stage::Update()
{
	player->Move();

	for (auto &i : floor)
	{
		i->Draw(Color(231, 0, 91));
	}
	player->Draw(Palette::Red);
}