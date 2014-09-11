#include "Stage.h"
#include "Player.h"
#include "Floor.h"
#include "Ladder.h"
#include "Barrel.h"
#include "Enemy.h"
#include "Drum.h"
#include "Hammer.h"
#include "Title.h"
#include "Clear.h"
#include "Reddy.h"

Stage *stage;


Stage::Stage()
{

	//		スマートポインタ宣言の仕方
	player.reset(new CPlayer());
	enemy.reset(new CEnemy());
	hammer.reset(new CHammer());
	reddy.reset(new CReddy());
	Title.reset(new CTitle());
	Clear.reset(new CClear());

	Flag = StageFlag::TITLE;

	Map();
}


Stage::~Stage()
{

}
void Stage::Map()
{
	const CSVReader map	(L"engine/csv/Map.csv");
	const CSVReader lad(L"engine/csv/Ladder.csv");
	const CSVReader bar(L"engine/csv/Barrel.csv");
	SoundAsset::Register(L"BGM", L"engine/MP3/BGM.mp3",true);
	SoundAsset::Register(L"Walk", L"engine/MP3/徒歩.mp3", true);
	SoundAsset::Register(L"Hammer", L"engine/MP3/ハンマー.mp3", true);

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
void Stage::GameStart()
{
	if (Flag == StageFlag::TITLE && Input::KeyEnter.clicked)
	{
		Flag = StageFlag::MAIN;
		SoundAsset(L"BGM").play();
	}
	if (Flag == StageFlag::CLEAR && Input::KeyEnter.clicked)
	{
		System::Exit();
	}
}
void Stage::GameClear()
{
	Flag = StageFlag::CLEAR;
	SoundAsset(L"BGM").stop();
	SoundAsset(L"Walk").stop();
	SoundAsset(L"Hammer").stop();
}
void Stage::Update()
{
	GameStart();

	if (Flag == StageFlag::MAIN)
	{
		player->Update();
		reddy->Update();
		enemy->Update();
	}
}
void Stage::Draw()
{

	if (Flag == StageFlag::MAIN)
	{
		for (int j = 0, max = OBJECT::ALL; j < max; j++)
		{
			for (auto &i : obj[j])
			{
				i->Draw();
			}
		}

		hammer->Draw();
		player->Draw();
		reddy->Draw();
		enemy->Draw();
		std::dynamic_pointer_cast<CEnemy>(enemy)->BulletDelete();

	}
		
	if (Flag == StageFlag::TITLE){ Title->Draw(); }
	if (Flag == StageFlag::CLEAR){ Clear->Draw(); }
}
void Stage::GameMain()
{
	Update();
	Draw();

}