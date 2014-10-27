/*

@author shinnnosuke hiratsuka
@date 2014.10.26

*/

#pragma once
#include "Actor.h"
#include <string>

class CPlayerMove;

class CMiniMapPlayer :public CActor
{
public:
	CMiniMapPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

	bool OnCollision;

private:
	std::unique_ptr<CPlayerMove> move;	///	ˆÚ“®ˆ—
};