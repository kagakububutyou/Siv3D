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
	MoveDirecData[MOVEDIREC::LEFT] = Point(-speed.x, 0);
	MoveDirecData[MOVEDIREC::RIGHT] = Point(speed.x, 0);
	MoveDirecData[MOVEDIREC::UP] = Point(0, -speed.y);
	MoveDirecData[MOVEDIREC::DOWN] = Point(0, speed.y);
}

void CBatteryMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CBatteryMove::Stop()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
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
	for (auto& wall : task->GetActor(CGameManager::SwitchWall))
	{
		if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
			wall->transform.GetPos(), wall->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Patroller])
		{
			if (Battery->transform.GetPos().y > wall->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall->transform.GetPos().y > Battery->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (Battery->transform.GetPos().x > wall->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall->transform.GetPos().x > Battery->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall1 : task->GetActor(CGameManager::SwitchWall1))
	{
		if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
			wall1->transform.GetPos(), wall1->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::SnakeCopter])
		{
			if (Battery->transform.GetPos().y > wall1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall1->transform.GetPos().y> Battery->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (Battery->transform.GetPos().x > wall1->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall1->transform.GetPos().x> Battery->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall2 : task->GetActor(CGameManager::SwitchWall2))
	{
		if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
			wall2->transform.GetPos(), wall2->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::TatteredId])
		{
			if (Battery->transform.GetPos().y > wall2->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall2->transform.GetPos().y> Battery->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (Battery->transform.GetPos().x > wall2->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall2->transform.GetPos().x  > Battery->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall3 : task->GetActor(CGameManager::SwitchWall3))
	{
		if (Collision::RectToRect(Battery->transform.GetPos(), Battery->transform.GetScale(),
			wall3->transform.GetPos(), wall3->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Battery])
		{
			if (Battery->transform.GetPos().y > wall3->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall3->transform.GetPos().y> Battery->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (Battery->transform.GetPos().x > wall3->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall3->transform.GetPos().x > Battery->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
///	ï˚å¸Çï‘Ç∑ä÷êî
CBatteryMove::MOVEDIREC CBatteryMove::Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale)
{
	int small[] = { player.x, enemy_pos.x + enemy_scale.x / 2 - scroll.x, player.y, enemy_pos.y + enemy_scale.y / 2 - scroll.y };
	int big[] = { enemy_pos.x - enemy_scale.x / 2 - scroll.x, player.x, enemy_pos.y - enemy_scale.y / 2 - scroll.y, player.y };
	MOVEDIREC direc[] = { MOVEDIREC::LEFT, MOVEDIREC::RIGHT, MOVEDIREC::UP, MOVEDIREC::DOWN };

	for (int i = 0; i < MOVEDIREC::DIREC; i++)
	{
		if (small[i] < big[i])
		{
			return direc[i];
		}
	}

	return MOVEDIREC::DOWN;
}
void CBatteryMove::Move(MOVEDIREC direc)
{
	VelocitySpeed(MoveDirecData[direc]);
}
void CBatteryMove::Update()
{
	auto player = (task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos());
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	auto battery_pos = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos());
	auto battery_scale = (task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetScale());

	Move(Direc(player, scroll, battery_pos, battery_scale));

	WallCollision();

	Stop();

	task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.Translate(velocity);
}

void CBatteryMove::Draw()
{

}