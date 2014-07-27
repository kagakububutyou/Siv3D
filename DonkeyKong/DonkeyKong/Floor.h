#pragma once
#include <Siv3D.hpp>

#include "OBJECT.h"

class CFloor:public COBJECT
{
private:

	//const Texture texture(L"Example/d6-red-dots.png");

public:

	CFloor(Float3 pos, Float3 size);
	~CFloor(){};

	void Draw();
};

