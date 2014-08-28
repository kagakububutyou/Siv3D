#pragma once
#include "OBJECT.h"
class CBullet :public COBJECT
{
private:
	float posY;
	float angle;
	float Gravity;

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
	void Death(){};
};

