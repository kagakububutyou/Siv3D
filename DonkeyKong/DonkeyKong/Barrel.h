#pragma once
#include "OBJECT.h"
class CBarrel :public COBJECT
{
private:

public:
	CBarrel(Float3 pos);
	~CBarrel(){};

	void Draw();
};

