#include "PatrollerMove.h"
#include "Patroller.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CPatrollerMove::CPatrollerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}

void CPatrollerMove::Start()
{

}

void CPatrollerMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CPatrollerMove::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.x < patroller->transform.GetPos().x - patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x - CMapRead::Size)
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}
void CPatrollerMove::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.x > patroller->transform.GetPos().x + patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CPatrollerMove::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y < patroller->transform.GetPos().y - patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CPatrollerMove::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y > patroller->transform.GetPos().y + patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
	{
		VelocitySpeed(Point(0, speed.y));
	}
}
void CPatrollerMove::Stop()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto patroll = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
	&&!task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CPatrollerMove::WallCollision()
{
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(patroller->transform.GetPos(), patroller->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			if (patroller->transform.GetPos().y > floor->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y > patroller->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (patroller->transform.GetPos().x > floor->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x > patroller->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall : task->GetActor(CGameManager::SwitchWall))
	{
		if (Collision::RectToRect(patroller->transform.GetPos(), patroller->transform.GetScale(),
			wall->transform.GetPos(), wall->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy1)
		{
			if (patroller->transform.GetPos().y > wall->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall->transform.GetPos().y > patroller->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (patroller->transform.GetPos().x > wall->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall->transform.GetPos().x > patroller->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall1 : task->GetActor(CGameManager::SwitchWall1))
	{
		if (Collision::RectToRect(patroller->transform.GetPos(), patroller->transform.GetScale(),
			wall1->transform.GetPos(), wall1->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy2)
		{
			if (patroller->transform.GetPos().y > wall1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall1->transform.GetPos().y> patroller->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (patroller->transform.GetPos().x > wall1->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall1->transform.GetPos().x> patroller->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall2 : task->GetActor(CGameManager::SwitchWall2))
	{
		if (Collision::RectToRect(patroller->transform.GetPos(), patroller->transform.GetScale(),
			wall2->transform.GetPos(), wall2->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy3)
		{
			if (patroller->transform.GetPos().y > wall2->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall2->transform.GetPos().y> patroller->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (patroller->transform.GetPos().x > wall2->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall2->transform.GetPos().x  > patroller->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall3 : task->GetActor(CGameManager::SwitchWall3))
	{
		if (Collision::RectToRect(patroller->transform.GetPos(), patroller->transform.GetScale(),
			wall3->transform.GetPos(), wall3->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy4)
		{
			if (patroller->transform.GetPos().y > wall3->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall3->transform.GetPos().y> patroller->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (patroller->transform.GetPos().x > wall3->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall3->transform.GetPos().x > patroller->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CPatrollerMove::Move()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y - patroller->transform.GetPos().y + patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size
		> player.x - patroller->transform.GetPos().x + patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		if (player.y < patroller->transform.GetPos().y - patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
		{
			VelocitySpeed(Point(0, -speed.y));
		}
		if(player.y > patroller->transform.GetPos().y + patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
		{
			VelocitySpeed(Point(0, speed.y));
		}
	}

}
void CPatrollerMove::Update()
{
	Right();
	Left();
	Up();
	Down();

	WallCollision();

	//Move();

	Stop();

	task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.Translate(velocity);
}

void CPatrollerMove::Draw()
{
	
}