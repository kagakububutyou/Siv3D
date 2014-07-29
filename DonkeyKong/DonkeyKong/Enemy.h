#pragma once
#include "OBJECT.h"
class CEnemy :public COBJECT
{
public:
	CEnemy();
	~CEnemy(){};

	void Draw();
	void Update();
};