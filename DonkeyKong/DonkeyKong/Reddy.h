#pragma once
#include "OBJECT.h"
class CReddy :public COBJECT
{
public:
	CReddy();
	~CReddy(){}

	void Draw();
	void Update();
	void Collision();
	void Death(){};
};

