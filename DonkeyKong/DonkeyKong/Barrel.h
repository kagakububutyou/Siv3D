#pragma once
#include "OBJECT.h"
class CBarrel :public COBJECT
{
private:

	Float3 pos[4];
public:
	CBarrel(int i);
	~CBarrel(){};

	void Draw();
};

