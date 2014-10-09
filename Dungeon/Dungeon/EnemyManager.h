/*

@author shinnnosuke hiratsuka
@date 2014.10.09

*/
#pragma once
#include "Actor.h"

class CEnemyManager:public CActor
{
public:
	CEnemyManager(std::shared_ptr<CTask> task);

	void Start();
	void Update();

};