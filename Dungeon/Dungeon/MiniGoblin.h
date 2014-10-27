/*

@author shinnnosuke hiratsuka
@date 2014.10.09

*/
#pragma once
#include "Actor.h"

class CMiniGoblin :public CActor
{
public:

	CMiniGoblin(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();
};