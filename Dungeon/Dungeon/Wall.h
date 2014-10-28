/*

@author shinnnosuke hiratsuka
@date 2014.10.27

*/
#pragma once
#include "Actor.h"

class CPlayerMove;

class CWall : public CActor
{
public:
	CWall(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:
	std::unique_ptr<CPlayerMove> move;	///	ˆÚ“®ˆ—

};

