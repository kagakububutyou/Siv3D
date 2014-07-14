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
	const CSVReader csv(L"Map.txt");
	const Font font(20);

	if (!csv)
	{
		MessageBox::Show(L"エラー", L"Map.txt の読み込みに失敗しました。");
		return;
	}
	Println(L"txt の行数: ", csv.rows - 1);

	Println(L"txt の 1 行目の列数: ", csv.columns(1));

	
	// 0 行目、1 列の要素
	const int MapX = csv.columns(1);
	const int MapY = csv.rows ;
	const int MapSize = csv.get<int>(0, 0);
	for (int j = 1; j <= MapY; j++)
	{
		for (int i = 0; i < MapX; i++)
		{
			Item item;
			item.Chip = csv.get<int>(j, i);
			items.push_back(item);
		}
	}
	int x = ((MapX - 1) / 2) * -1;
	int y = ((MapY - 1) / 2);
	for (auto &i : items)
	{
		int posx, posy;
		//floor.emplace_back(new CFloor(Float3(j.pos)));

		//Println(i.Chip);
		switch (i.Chip)
		{
		case 1:

			posx = MapSize * x;
			posy = MapSize * y;

			floor.emplace_back(new CFloor(Float3(posx, posy, 0), Float3(MapSize, MapSize, MapSize)));

			//Println(posx);

			break;
		case -1:

			x = ((MapX / 2) * -1);
			y -= 1;

			break;
		default:


			break;
		}
		x += 1;
	}


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