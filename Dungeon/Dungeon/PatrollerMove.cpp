#include "PatrollerMove.h"
#include "Patroller.h"
#include "EnemyManager.h"

#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"

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

	if (player.x < patroller->transform.GetPos().x - patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}
void CPatrollerMove::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.x > patroller->transform.GetPos().x + patroller->transform.GetScale().x / 2 - pos->transform.GetPos().x)
	{
		
	}
}

void CPatrollerMove::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y < patroller->transform.GetPos().y - patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{
		
	}
}

void CPatrollerMove::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.y > patroller->transform.GetPos().y + patroller->transform.GetScale().y / 2 - pos->transform.GetPos().y)
	{

	}
}
void CPatrollerMove::Stop()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto patroller = (task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0));

	if (player.x == patroller->transform.GetPos().x - pos->transform.GetPos().x)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CPatrollerMove::Update()
{
	Right();
	Left();
	Up();
	Down();

	Stop();

	task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.Translate(velocity);
}

void CPatrollerMove::Draw()
{
	
}