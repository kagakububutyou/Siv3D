#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class CPlayer;
class CEnemy;
class CFloor;
class COBJECT;

struct Item
{
	Float3 Pos;
	Float3 Size;
	Color color;
};

class Stage
{
private:
	
public:
	enum OBJECT
	{
		FLOOR,			//	床
		LADDER,		//	梯
		BARREL,		//	樽
		DRUM,			//	ドラム缶(輸送用)

		ALL,
	};


	Stage();
	~Stage();

	void Map();
	void Update();
	void Draw();
	void GameMain();
	//		スマートポインタ
	//		もう少し具体的に
	std::vector<std::unique_ptr<COBJECT>> obj[OBJECT::ALL];
	std::unique_ptr<COBJECT> player;
	std::unique_ptr<COBJECT> enemy;
	std::vector<Item> items;

	const static int Width = 512;		//	幅
	const static int Height = 448;		//	高さ

};

extern Stage *stage;