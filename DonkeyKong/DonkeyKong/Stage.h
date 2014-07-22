#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class CPlayer;
class CFloor;

struct Item
{
	Float3 Chip;
};

class Stage
{
private:

public:
	Stage();
	~Stage();

	void Map();
	void Update();
	//		スマートポインタ
	std::vector<std::unique_ptr<CFloor>> floor;
	std::unique_ptr<CPlayer> player;
	std::vector<Item> items;

	const static int Width = 512;		//	幅
	const static int Height = 448;		//	高さ

};

extern Stage *stage;