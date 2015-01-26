#include "TatteredIdMove.h"
#include "TatteredId.h"
#include "EnemyManager.h"

#include "Player.h"
#include "PlayerAttack.h"
#include "GameManager.h"
#include "Scroll.h"
#include "Collision.h"
#include "MapRead.h"

#include "Transform.h"
#include "GameApplication.h"

CTatteredIdMove::CTatteredIdMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}

void CTatteredIdMove::Start()
{

}

void CTatteredIdMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CTatteredIdMove::Left()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.x < TatteredId->transform.GetPos().x - TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x - CMapRead::Size)
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}
void CTatteredIdMove::Right()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.x > TatteredId->transform.GetPos().x + TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CTatteredIdMove::Up()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y < TatteredId->transform.GetPos().y - TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CTatteredIdMove::Down()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y > TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
	{
		VelocitySpeed(Point(0, speed.y));
	}
}
void CTatteredIdMove::Stop()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto patroll = task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (!task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior
		&&!task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isCollision)
	{
		VelocitySpeed(Point(0, 0));
	}
}
void CTatteredIdMove::WallCollision()
{
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(TatteredId->transform.GetPos(), TatteredId->transform.GetScale(),
			floor->transform.GetPos(), floor->transform.GetScale()))
		{
			if (TatteredId->transform.GetPos().y > floor->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y > TatteredId->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (TatteredId->transform.GetPos().x > floor->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x > TatteredId->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall : task->GetActor(CGameManager::SwitchWall))
	{
		if (Collision::RectToRect(TatteredId->transform.GetPos(), TatteredId->transform.GetScale(),
			wall->transform.GetPos(), wall->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Patroller])
		{
			if (TatteredId->transform.GetPos().y > wall->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall->transform.GetPos().y > TatteredId->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (TatteredId->transform.GetPos().x > wall->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall->transform.GetPos().x > TatteredId->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall1 : task->GetActor(CGameManager::SwitchWall1))
	{
		if (Collision::RectToRect(TatteredId->transform.GetPos(), TatteredId->transform.GetScale(),
			wall1->transform.GetPos(), wall1->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::SnakeCopter])
		{
			if (TatteredId->transform.GetPos().y > wall1->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall1->transform.GetPos().y> TatteredId->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (TatteredId->transform.GetPos().x > wall1->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall1->transform.GetPos().x> TatteredId->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall2 : task->GetActor(CGameManager::SwitchWall2))
	{
		if (Collision::RectToRect(TatteredId->transform.GetPos(), TatteredId->transform.GetScale(),
			wall2->transform.GetPos(), wall2->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::TatteredId])
		{
			if (TatteredId->transform.GetPos().y > wall2->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall2->transform.GetPos().y> TatteredId->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (TatteredId->transform.GetPos().x > wall2->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall2->transform.GetPos().x  > TatteredId->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall3 : task->GetActor(CGameManager::SwitchWall3))
	{
		if (Collision::RectToRect(TatteredId->transform.GetPos(), TatteredId->transform.GetScale(),
			wall3->transform.GetPos(), wall3->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[CPlayerAttack::EnemyName::Battery])
		{
			if (TatteredId->transform.GetPos().y > wall3->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall3->transform.GetPos().y> TatteredId->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (TatteredId->transform.GetPos().x > wall3->transform.GetPos().x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall3->transform.GetPos().x > TatteredId->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CTatteredIdMove::Move()
{
	Point  player = Point(CGameApplication::ScreenWidth / 2, CGameApplication::ScreenHeight / 2);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0));
	auto TatteredId = (task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0));

	if (player.y - TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size
		> player.x - TatteredId->transform.GetPos().x + TatteredId->transform.GetScale().x / 2 - pos->transform.GetPos().x + CMapRead::Size)
	{
		if (player.y < TatteredId->transform.GetPos().y - TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y - CMapRead::Size)
		{
			VelocitySpeed(Point(0, -speed.y));
		}
		if (player.y > TatteredId->transform.GetPos().y + TatteredId->transform.GetScale().y / 2 - pos->transform.GetPos().y + CMapRead::Size)
		{
			VelocitySpeed(Point(0, speed.y));
		}
	}

}
void CTatteredIdMove::Update()
{
	Right();
	Left();
	Up();
	Down();

	WallCollision();

	//Move();

	Stop();

	task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0)->transform.Translate(velocity);
}

void CTatteredIdMove::Draw()
{

}