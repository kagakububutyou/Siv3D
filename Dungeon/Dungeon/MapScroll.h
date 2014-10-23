/*

@author shinnnosuke hiratsuka
@date 2014.10.23

*/
#pragma once
#include "Actor.h"
#include <string>

class CMapMove;

class CMapScroll :public CActor
{
public:
	CMapScroll(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:
	std::unique_ptr<CMapMove> move;	///	ˆÚ“®ˆ—
	//std::unique_ptr<CPlayerCamera> camera;	///	ƒJƒƒ‰ˆ—
};