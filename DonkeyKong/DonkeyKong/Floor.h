#pragma once
#include <Siv3D.hpp>

#include "OBJECT.h"

class CFloor:public COBJECT
{
private:
	Model *model;
	Texture *texture;
public:

	CFloor(Float3 pos, Float3 size);
	~CFloor(){};

	void Draw();
	void Update(){};
	void Death(){};
};

