#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class CPlayer;
class CFloor;

struct Item
{
	int Chip;
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

	const static int Width = 560;
	const static int Height = 640;

};

extern Stage *stage;