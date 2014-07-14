#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class CPlayer;
class CFloor;

struct Item
{
	Float3 pos;
};

class Stage
{
private:

public:
	Stage();
	~Stage();

	void Update();
	//		スマートポインタ
	std::vector<std::unique_ptr<CFloor>> floor;
	std::unique_ptr<CPlayer> player;
	std::vector<Item> items;

};

extern Stage *stage;