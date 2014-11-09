/*

@author shinnnosuke hiratsuka
@date 2014.10.16

*/
#pragma once
#include "Actor.h"
class CUpStairs :public CActor
{
public:
	CUpStairs(std::shared_ptr<CTask> task, Point pos);

	void Start();

	void Draw();

private:

};
