#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class COBJECT;
class CTitle;
class CClear;

struct Item
{
	Float3 Pos;
	Float3 Size;
	Color color;
};

class Stage
{
private:
	
	enum StageFlag
	{
		TITLE,
		MAIN,
		CLEAR,
	};

	StageFlag Flag;

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

	void GameStart();
	void GameClear();

	void Draw();
	void GameMain();
	//		スマートポインタ
	//		もう少し具体的に
	std::vector<std::unique_ptr<COBJECT>> obj[OBJECT::ALL];
	std::unique_ptr<COBJECT> player;
	std::unique_ptr<COBJECT> reddy;
	std::shared_ptr<COBJECT> enemy;
	std::unique_ptr<COBJECT> hammer;

	std::unique_ptr<CTitle> Title;
	std::unique_ptr<CClear> Clear;

	const static int Width = 512;		//	幅
	const static int Height = 448;		//	高さ

};

extern Stage *stage;