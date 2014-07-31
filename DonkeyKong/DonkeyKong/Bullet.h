#pragma once
#include "OBJECT.h"
class CBullet :public COBJECT
{
private:
	float posY;

private:

	float Speed;
	bool CollisionFloor;

public:
	CBullet();
	~CBullet(){};

	void Move();
	void Collision();

	void Draw();
	void Update();
};

