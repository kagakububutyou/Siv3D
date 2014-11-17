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

	static const std::string Patroller;	//	ƒSƒuƒŠƒ“
	static const std::string MiniGoblin;	//


	static const int GoblinPosition = 10;		//	ƒSƒuƒŠƒ“‚ÌˆÊ’u

private:

	int TransformMapToScreenX(const int x);
	int TransformMapToScreenY(const int y);

	int TransformMiniMapToScreenX(const int x);
	int TransformMiniMapToScreenY(const int y);

	std::unique_ptr<CMapRead> map_read;

};