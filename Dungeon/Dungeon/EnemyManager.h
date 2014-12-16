/*

@author shinnnosuke hiratsuka
@date 2014.10.09

*/
#pragma once
#include "Actor.h"

class CMapRead;

class CEnemyManager:public CActor
{
public:
	CEnemyManager(std::shared_ptr<CTask> task);

	void Start();
	void Update();

	static const std::string SnakeCopter;
	static const std::string SnakeCopterAttack;
	static const std::string SnakeCopter1;
	static const std::string SnakeCopter1Attack;
	static const std::string Patroller;
	static const std::string PatrollerAttack;
	static const std::string Battery;
	static const std::string BatteryAttack;
	static const std::string MiniGoblin;	//


	static const int PatrollerPosition = 10;		
	static const int SnakeCopterPosition = 11;
	static const int BatteryPosition = 12;
	static const int SnakeCopter1Position = 13;

private:

	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	int TransformMiniMapToScreenX(const int x);
	int TransformMiniMapToScreenY(const int y);

	std::unique_ptr<CMapRead> map_read;

};