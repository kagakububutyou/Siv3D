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
speed(Point(16.0f, 16.0f))
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
	auto patroll = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CPatrollerMove::WallCollision()
{
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(patroller->transform.GetPos(), patroller->transform.GetScale(),
			floor->transform.GetPos() - pos->transform.GetPos(), floor->transform.GetScale()))
		{

			if (patroller->transform.GetPos().y > floor->transform.GetPos().y - pos->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y - pos->transform.GetPos().y > patroller->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (patroller->transform.GetPos().x > floor->transform.GetPos().x - pos->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x - pos->transform.GetPos().x > patroller->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CPatrollerMove::Update()
{
	Right();
	Left();
	Up();
	Down();

	//WallCollision();

	Stop();

	task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.Translate(velocity);
}

void CPatrollerMove::Draw()
{
	
}