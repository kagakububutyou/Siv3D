#pragma once
#include "OBJECT.h"
class CBullet :public COBJECT
{
public:
	CBullet();
	~CBullet(){};

	void Draw();
	void Update();


};

