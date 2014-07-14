#include "Stage.h"
#include "Player.h"
#include "Floor.h"

Stage *stage;


Stage::Stage()
{
	const CSVReader csv(L"Map.csv");

	if (!csv)
	{
		MessageBox::Show(L"�G���[", L"Map.csv �̓ǂݍ��݂Ɏ��s���܂����B");
		return;
	}
	Println(L"CSV �̍s��: ", csv.rows);

	Println(L"CSV �� 0 �s�ڂ̗�: ", csv.columns(0));

	//		�X�}�[�g�|�C���^�錾�̎d��
	player.reset(new CPlayer());
	//floor.reset(new CFloor(Float3(0,-200,0)));
	// 0 �s�ځA0 ��̗v�f
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