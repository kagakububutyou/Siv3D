/*

@author shinnnosuke hiratsuka
@date 2014.11.17

*/
#pragma once
#include "Actor.h"

class CPatrollerMove;

class CPatroller :public CActor
{
public:

	CPatroller(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CPatrollerMove> move;	///	ˆÚ“®ˆ—

	bool isCollision;

	const Font font;
};