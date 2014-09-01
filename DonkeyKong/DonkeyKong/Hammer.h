#pragma once
#include "OBJECT.h"
class CHammer :	public COBJECT
{
private:

	bool IsCollisionPlayer;

public:
	CHammer();
	~CHammer(){};

	void Collision();
	void Move();
	void Draw();
	void Update();
	void Death(){};
};

