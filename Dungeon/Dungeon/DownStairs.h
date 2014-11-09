//DownStairs
/*

@author shinnnosuke hiratsuka
@date 2014.10.16

*/
#pragma once
#include "Actor.h"
class CDownStairs :public CActor
{
public:
	CDownStairs(std::shared_ptr<CTask> task, Point pos);

	void Start();

	void Draw();

private:

};
