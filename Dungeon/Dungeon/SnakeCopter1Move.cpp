#include "SnakeCopter1Move.h"
#include "SnakeCopter1.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CSnakeCopter1Move::CSnakeCopter1Move(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(16.0f, 16.0f))
{

}

void CSnakeCopter1Move::Start()
{

}

void CSnakeCopter1Move::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CSnakeCopter1Move::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.x < SnakeCopter1->transform.GetPos().x - SnakeCopter1->transform.GetScale().x / 2 - pos->transform.GetPos().x - CMapRead::Size)
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}
void CSnakeCopter1Move::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.x > SnakeCopter1->transform.GetPos().x + SnakeCopter1->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CSnakeCopter1Move::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.y < SnakeCopter1->transform.GetPos().y - SnakeCopter1->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CSnakeCopter1Move::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (player.y > SnakeCopter1->transform.GetPos().y + SnakeCopter1->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
	{
		VelocitySpeed(Point(0, speed.y));
	}
}
void CSnakeCopter1Move::Stop()
{
	auto patroll = task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CSnakeCopter1Move::WallCollision()
{
	auto SnakeCopter1 = (task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0));

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(SnakeCopter1->transform.GetPos(), SnakeCopter1->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			if (SnakeCopter1->transform.GetPos().y > floor->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y > SnakeCopter1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter1->transform.GetPos().x > floor->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x > SnakeCopter1->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall : task->GetActor(CGameManager::SwitchWall))
	{
		if (Collision::RectToRect(SnakeCopter1->transform.GetPos(), SnakeCopter1->transform.GetScale(),
			wall->transform.GetPos() , wall->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy1)
		{
			if (SnakeCopter1->transform.GetPos().y > wall->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall->transform.GetPos().y > SnakeCopter1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter1->transform.GetPos().x > wall->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall->transform.GetPos().x > SnakeCopter1->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall1 : task->GetActor(CGameManager::SwitchWall1))
	{
		if (Collision::RectToRect(SnakeCopter1->transform.GetPos(), SnakeCopter1->transform.GetScale(),
			wall1->transform.GetPos(), wall1->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy2)
		{
			if (SnakeCopter1->transform.GetPos().y > wall1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall1->transform.GetPos().y> SnakeCopter1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter1->transform.GetPos().x > wall1->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall1->transform.GetPos().x> SnakeCopter1->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall2 : task->GetActor(CGameManager::SwitchWall2))
	{
		if (Collision::RectToRect(SnakeCopter1->transform.GetPos(), SnakeCopter1->transform.GetScale(),
			wall2->transform.GetPos(), wall2->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy3)
		{
			if (SnakeCopter1->transform.GetPos().y > wall2->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall2->transform.GetPos().y> SnakeCopter1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter1->transform.GetPos().x > wall2->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall2->transform.GetPos().x  > SnakeCopter1->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall3 : task->GetActor(CGameManager::SwitchWall3))
	{
		if (Collision::RectToRect(SnakeCopter1->transform.GetPos(), SnakeCopter1->transform.GetScale(),
			wall3->transform.GetPos(), wall3->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy4)
		{
			if (SnakeCopter1->transform.GetPos().y > wall3->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall3->transform.GetPos().y> SnakeCopter1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (SnakeCopter1->transform.GetPos().x > wall3->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall3->transform.GetPos().x > SnakeCopter1->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CSnakeCopter1Move::Update()
{
	Right();
	Left();
	Up();
	Down();

	WallCollision();

	Stop();

	task->GetComponent<CSnakeCopter1>(CEnemyManager::SnakeCopter1, 0)->transform.Translate(velocity);
}

void CSnakeCopter1Move::Draw()
{
	
}