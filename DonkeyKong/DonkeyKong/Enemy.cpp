#include "Enemy.h"
#include "Stage.h"
#include "Collision.h"

CEnemy::CEnemy()
{
	Pos = Float3(-136, 348, 0);

	Velocity = Float3(0, 0, 0);

	Size = Float3(64, 64, 16);

	color = Color(171, 91, 0);

	ShotTime = 3;

	ShotTiming();
}
void CEnemy::ShotTiming()
{
	ShotTime = Random(ShotMinTime, ShotMaxTime);
}

void CEnemy::CreateShot()
{
	ShotTime--;
	if (ShotTime == 0)
	{
		bullet.emplace_back(new CBullet());
		ShotTiming();
	}
}
void CEnemy::Collision()
{
	//	ƒhƒ‰ƒ€ŠÊ(—A‘——p)
	for (auto &i : stage->obj[stage->DRUM])
	{
		for (auto &j : bullet)
		{
			if (Collision::IsCollisionBox(j->Pos, j->Size, i->Pos, i->Size))
			{
				bullet.erase(std::remove(bullet.begin(), bullet.end(), j), bullet.end());
			}
		}
	}
}
void CEnemy::Update()
{
	CreateShot();
	Collision();

	for (auto &i : bullet)
	{
		i->Update();
	}
}
void CEnemy::Draw()
{
	Box(Pos, Size).draw(color);

	for (auto &i : bullet)
	{
		i->Draw();
	}
}
