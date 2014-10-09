/*

@author shinnnosuke hiratsuka
@date 2014.10.09

*/
#pragma once
#include "Actor.h"

class CGoblin :public CActor
{
public:

	CGoblin(std::shared_ptr<CTask> task);
	void Start();
	void Update();
	void Draw();
};