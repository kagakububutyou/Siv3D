#pragma once
#include "OBJECT.h"
class CLadder :public COBJECT
{
public:
	CLadder(Float3 pos, Float3 size);
	~CLadder(){};

	void Draw();
	void Update();
};

