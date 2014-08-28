#include "Enemy.h"
#include "Stage.h"
#include "Collision.h"

/*
	
	ドンキーコング

*/

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
	//	ドラム缶(輸送用)
	/*
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
	//*/
	for (auto &i : bullet)
	{
		for (auto &j : stage->obj[stage->DRUM])
		{
			if (Collision::IsCollisionBox(i->Pos, i->Size, j->Pos, j->Size))
			{
				bullet.erase(std::remove(bullet.begin(), bullet.end(), i), bullet.end());
			}
		}
		if (Collision::IsCollisionBox(i->Pos, i->Size, stage->player->Pos, stage->player->Size))
		{
			bullet.erase(std::remove(bullet.begin(), bullet.end(), i), bullet.end());
			stage->player->Death();
		}
	}
}
void CEnemy::Death()
{

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
