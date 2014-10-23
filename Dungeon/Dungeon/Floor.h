/*

@author shinnnosuke hiratsuka
@date 2014.10.16

*/
#pragma once
#include "Actor.h"
class CPlayerMove;
class CFloor :	public CActor
{
public:
	CFloor(std::shared_ptr<CTask> task,Point pos);

	void Update();
	void Draw();

private:

	std::unique_ptr<CPlayerMove> scroll;	///	ˆÚ“®ˆ—
	
};

