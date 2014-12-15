#include "BatteryMove.h"
#include "Battery.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CBatteryMove::CBatteryMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}

void CBatteryMove::Start()
{

}

void CBatteryMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CBatteryMove::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.x < Battery->transform.GetPos().x - Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x - CMapRead::Size)
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}
void CBatteryMove::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.x > Battery->transform.GetPos().x + Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CBatteryMove::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y < Battery->transform.GetPos().y - Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CBatteryMove::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y > Battery->transform.GetPos().y + Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
	{
		VelocitySpeed(Point(0, speed.y));
	}
}
void CBatteryMove::Stop()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto patroll = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&&!task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CBatteryMove::WallCollision()
{
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			if (Battery->transform.GetPos().y > floor->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y > Battery->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (Battery->transform.GetPos().x > floor->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x > Battery->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CBatteryMove::Move()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto Battery = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0));

	if (player.y - Battery->transform.GetPos().y + Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size
		> player.x - Battery->transform.GetPos().x + Battery->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		if (player.y < Battery->transform.GetPos().y - Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
		{
			VelocitySpeed(Point(0, -speed.y));
		}
		if (player.y > Battery->transform.GetPos().y + Battery->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
		{
			VelocitySpeed(Point(0, speed.y));
		}
	}

}
void CBatteryMove::Update()
{
	Right();
	Left();
	Up();
	Down();

	WallCollision();

	//Move();

	Stop();

	task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.Translate(velocity);
}

void CBatteryMove::Draw()
{

}