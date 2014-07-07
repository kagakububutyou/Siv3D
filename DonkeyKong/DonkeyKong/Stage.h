#pragma once
#include <Siv3D.hpp>
#include <memory>
#include <vector>

class CPlayer;
class CFloor;

class Stage
{
private:

public:
	Stage();
	~Stage();

	void Update();
	//		スマートポインタ
	std::unique_ptr<CFloor> floor;
	std::unique_ptr<CPlayer> player;

};

extern Stage *stage;