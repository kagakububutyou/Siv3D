/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Actor.h"
#include <string>

class CPlayerMove;
class CPlayerCamera;

class CPlayer :public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:
	std::unique_ptr<CPlayerMove> move;	///	ˆÚ“®ˆ—
};