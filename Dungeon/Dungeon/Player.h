/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Actor.h"
#include <string>

class CPlayerMove;

class CPlayer :public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task);

	void Start();
	void Update();
	void Draw();

private:
	std::unique_ptr<CPlayerMove> move;	///	ˆÚ“®ˆ—
};