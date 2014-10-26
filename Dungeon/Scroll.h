/*

@author shinnnosuke hiratsuka
@date 2014.10.26

*/

#pragma once
#include "Actor.h"
#include <string>

class CPlayerMove;

class CScroll :public CActor
{
public:
	CScroll(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:
	std::unique_ptr<CPlayerMove> move;	///	ˆÚ“®ˆ—
};