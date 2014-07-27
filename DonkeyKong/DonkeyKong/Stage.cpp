#include "Stage.h"
#include "Player.h"
#include "Floor.h"
#include "Ladder.h"
Stage *stage;


Stage::Stage()
{

	//		�X�}�[�g�|�C���^�錾�̎d��
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
		MessageBox::Show(L"�G���[", L"�ǂݍ��݂Ɏ��s���܂����B");
		return;
	}
	Println(L"csv �̍s��: ", map.rows - 1);

	Println(L"csv �� 1 �s�ڂ̗�: ", map.columns(1));

	
	// 0 �s�ځA2 ��̗v�f
	int MapWidth = map.columns(1);
	int MapHeight = map.rows;
	Float3 MapSize = map.get<Float3>(0, 0);
	for (int j = 1; j < MapHeight; j++)
	{
		for (int i = 0; i < MapWidth; i++)
		{
			floor.emplace_back(new CFloor(Float3(map.get<Float3>(j, i)), MapSize));
		}
	}
	MapWidth = lad.columns(1);
	
	for (int i = 0; i < MapWidth; i++)
	{
		Item item;
		item.Pos = lad.get<Float3>(1, i);
		item.Size = lad.get<Float3>(2, i);
		ladder.emplace_back(new CLadder(item.Pos, item.Size));
	}//*/

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
		i->Draw();
	}
	for (auto &i:ladder)
	{
		i->Draw();
	}
	player->Draw();
}