#include "Stage.h"
#include "Player.h"
#include "Floor.h"

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
	const CSVReader csv(L"Map.csv");
	const Font font(20);

	if (!csv)
	{
		MessageBox::Show(L"�G���[", L"Map.txt �̓ǂݍ��݂Ɏ��s���܂����B");
		return;
	}
	Println(L"csv �̍s��: ", csv.rows - 1);

	Println(L"csv �� 1 �s�ڂ̗�: ", csv.columns(1));

	
	// 0 �s�ځA1 ��̗v�f
	const int MapX = csv.get<int>(0, 2);
	const int MapY = csv.rows ;
	const int MapSize = csv.get<int>(0, 0);
	for (int j = 1; j <= MapY; j++)
	{
		for (int i = 0; i < MapX; i++)
		{
			Item item;
			item.Chip = csv.get<Float3>(j, i);
			items.push_back(item);
		}
	}
	for (auto &i : items)
	{
		floor.emplace_back(new CFloor(Float3(i.Chip), Float3(MapSize, MapSize, MapSize)));
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