#include "SnakeCopterMove.h"
#include "SnakeCopter.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CSnakeCopterMove::CSnakeCopterMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(16.0f, 16.0f))
{

}

void CSnakeCopterMove::Start()
{

}

void CSnakeCopterMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CSnakeCopterMove::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.x < SnakeCopter->transform.GetPos().x - SnakeCopter->transform.GetScale().x / 2 - pos->transform.GetPos().x - CMapRead::Size)
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}
void CSnakeCopterMove::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.x > SnakeCopter->transform.GetPos().x + SnakeCopter->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CSnakeCopterMove::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.y < SnakeCopter->transform.GetPos().y - SnakeCopter->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CSnakeCopterMove::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (player.y > SnakeCopter->transform.GetPos().y + SnakeCopter->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
	{
		VelocitySpeed(Point(0, speed.y));
	}
}
void CSnakeCopterMove::Stop()
{
	auto patroll = task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CSnakeCopterMove::WallCollision()
{
	auto SnakeCopter = (task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0));

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(SnakeCopter->transform.GetPos(), SnakeCopter->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			if (SnakeCopter->transform.GetPos().y > floor->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y > SnakeCopter->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter->transform.GetPos().x > floor->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x > SnakeCopter->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall : task->GetActor(CGameManager::SwitchWall))
	{
		if (Collision::RectToRect(SnakeCopter->transform.GetPos(), SnakeCopter->transform.GetScale(),
			wall->transform.GetPos(), wall->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Patroller])
		{
			if (SnakeCopter->transform.GetPos().y > wall->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall->transform.GetPos().y > SnakeCopter->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter->transform.GetPos().x > wall->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall->transform.GetPos().x > SnakeCopter->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall1 : task->GetActor(CGameManager::SwitchWall1))
	{
		if (Collision::RectToRect(SnakeCopter->transform.GetPos(), SnakeCopter->transform.GetScale(),
			wall1->transform.GetPos(), wall1->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::SnakeCopter])
		{
			if (SnakeCopter->transform.GetPos().y > wall1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall1->transform.GetPos().y> SnakeCopter->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter->transform.GetPos().x > wall1->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall1->transform.GetPos().x> SnakeCopter->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall2 : task->GetActor(CGameManager::SwitchWall2))
	{
		if (Collision::RectToRect(SnakeCopter->transform.GetPos(), SnakeCopter->transform.GetScale(),
			wall2->transform.GetPos(), wall2->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::TatteredId])
		{
			if (SnakeCopter->transform.GetPos().y > wall2->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall2->transform.GetPos().y> SnakeCopter->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter->transform.GetPos().x > wall2->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall2->transform.GetPos().x  > SnakeCopter->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall3 : task->GetActor(CGameManager::SwitchWall3))
	{
		if (Collision::RectToRect(SnakeCopter->transform.GetPos(), SnakeCopter->transform.GetScale(),
			wall3->transform.GetPos(), wall3->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Battery])
		{
			if (SnakeCopter->transform.GetPos().y > wall3->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall3->transform.GetPos().y> SnakeCopter->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter->transform.GetPos().x > wall3->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall3->transform.GetPos().x > SnakeCopter->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CSnakeCopterMove::Update()
{
	Right();
	Left();
	Up();
	Down();

	WallCollision();

	Stop();

	task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0)->transform.Translate(velocity);
}

void CSnakeCopterMove::Draw()
{
	
}