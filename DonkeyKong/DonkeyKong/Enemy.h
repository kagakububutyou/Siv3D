#pragma once
#include <vector>
#include "OBJECT.h"
#include "Bullet.h"


class CEnemy :public COBJECT
{
private:
	
	const int ShotMaxTime = 400;
	const int ShotMinTime = 100;
	int ShotTime;

public:
	CEnemy();
	~CEnemy(){};

	std::vector<std::unique_ptr<CBullet>> bullet;

	void Draw();
	void Update();
	void Death();
	void BulletDelete();

	void ShotTiming();
	void CreateShot();
	void Collision();
};