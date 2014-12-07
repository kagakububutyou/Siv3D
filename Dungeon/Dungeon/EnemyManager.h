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
	static const std::string Patroller;
	static const std::string PatrollerAttack;
	static const std::string MiniGoblin;	//


	static const int PatrollerPosition = 10;		
	static const int SnakeCopterPosition = 11;

private:

	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	int TransformMiniMapToScreenX(const int x);
	int TransformMiniMapToScreenY(const int y);

	std::unique_ptr<CMapRead> map_read;

};