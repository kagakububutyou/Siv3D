#pragma once
#include <Siv3D.hpp>

#include "OBJECT.h"

class CFloor:public COBJECT
{
private:

public:

	CFloor(Float3 pos, Float3 size);
	~CFloor(){};

	void Draw();
	void Update();
};

