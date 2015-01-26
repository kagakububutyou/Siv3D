#include "PlayerMove.h"
#include "CharacterController.h"
#include "Player.h"
#include "Floor.h"
#include "GameManager.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "MiniMapPlayer.h"

#include "Collision.h"

#include "Patroller.h"
#include "SnakeCopter.h"
#include "TatteredId.h"
#include "Battery.h"
#include "MiniGoblin.h"
#include "EnemyManager.h"

#include "Wall.h"
#include "MapRead.h"
#include "PlayerAttack.h"

CPlayerMove::CPlayerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
state(State::Live),
velocity(Point(0, 0)),
speed(Point(16.0f, 16.0f))
{

}
void CPlayerMove::Start()
{
	MoveDirecData[MOVEDIREC::LEFT] = Point(-speed.x, 0);
	MoveDirecData[MOVEDIREC::RIGHT] = Point(speed.x, 0);
	MoveDirecData[MOVEDIREC::UP] = Point(0, -speed.y);
	MoveDirecData[MOVEDIREC::DOWN] = Point(0, speed.y);

}
void CPlayerMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}
void CPlayerMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		Move(MOVEDIREC::LEFT);
	}
}
void CPlayerMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		Move(MOVEDIREC::RIGHT);
	}
}
void CPlayerMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		Move(MOVEDIREC::UP);
	}
}
void CPlayerMove::Down()
{
	if (CharacterController::DownMoveKey())
	{

		Move(MOVEDIREC::DOWN);
		/*
		VelocitySpeed(Point(0, speed.y));

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->HitAttack();
		//*/
	}
}
void CPlayerMove::Stop()
{
	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey()
		&& !CharacterController::UpMoveKey() && !CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, 0));

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = false;
	}
}
void CPlayerMove::Move(MOVEDIREC direc)
{
	//VelocitySpeed(MoveDirecData[direc]);

	velocity = MoveDirecData[direc];

	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->HitAttack();
}
CPlayerMove::MOVEDIREC CPlayerMove::MoveDirec(Point player, Point object, Point scroll)
{
	int small[] = { player.x, object.x - scroll.x, player.y, object.y - scroll.y };
	int big[] = { object.x - scroll.x, player.x, object.y - scroll.y, player.y };
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
void CPlayerMove::CollisionMoveDirec(Point player, Point object, Point scroll)
{
	int small[] = { player.x, object.x - scroll.x, player.y, object.y - scroll.y };
	int big[] = { object.x - scroll.x, player.x, object.y - scroll.y, player.y };
	//MOVEDIREC direc[] = { MOVEDIREC::RIGHT, MOVEDIREC::LEFT, MOVEDIREC::DOWN, MOVEDIREC::UP};
	Point direc[] = { Point(-speed.x, 0), Point(speed.x, 0), Point(0, -speed.y), Point(0, speed.y) };
	for (int i = 0; i < MOVEDIREC::DIREC; i++)
	{
		if (small[i] < big[i])
		{
			VelocitySpeed(direc[i]);
			//return direc[i];
		}
	}
	//return MOVEDIREC::DOWN;
}
void CPlayerMove::WallCollision()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto scroll = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());
	std::vector<std::shared_ptr<CActor>> walls[]	= {	task->GetActor(CGameManager::SwitchWall),
																		task->GetActor(CGameManager::SwitchWall1),
																		task->GetActor(CGameManager::SwitchWall2),
																		task->GetActor(CGameManager::SwitchWall3) };
	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			floor->transform.GetPos() - scroll, floor->transform.GetScale()))
		{
			CollisionMoveDirec(player->transform.GetPos(), floor->transform.GetPos(), scroll);
		}
	}
	for (int i = 0; i < CPlayerAttack::EnemyName::Max; i++)
	{
		for (auto& wall : walls[i])
		{
			if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
				wall->transform.GetPos() - scroll, wall->transform.GetScale())
				&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemys[i])
			{
				CollisionMoveDirec(player->transform.GetPos(), wall->transform.GetPos(), scroll);
			}
		}
	}
}
void CPlayerMove::knockBack()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.GetPos();
	auto scroll = task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos();
	auto patroller = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0)->transform.GetPos();
	auto s = task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0)->transform.GetPos();
	auto t = task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0)->transform.GetPos();
	auto b = task->GetComponent<CBattery>(CEnemyManager::Battery, 0)->transform.GetPos();

	Point enemy[] = { patroller, s, t, b };
	for (int i = 0; i < EnemyName::Max; i++)
	{
		if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isHits[i])
		{
			Move(MoveDirec(player, enemy[i], scroll));
		}
	}
}
void CPlayerMove::EnemyCollision()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	for (auto& enemy : task->GetActor(CGameManager::EnemyManager))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			enemy->transform.GetPos() - pos, enemy->transform.GetScale()))
		{
			if (player->transform.GetPos().y > enemy->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (enemy->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > enemy->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (enemy->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CPlayerMove::Update()
{
	
	Right(),
	Left();
	Up();
	Down();

	Stop();

	WallCollision();
	EnemyCollision();
	knockBack();
		
	task->GetComponent<CMiniMapPlayer>(CGameManager::MiniPlayer, 0)->transform.Translate(Point(velocity.x / CMiniMap::MapScale, velocity.y / CMiniMap::MapScale));
	task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.Translate(velocity);
}
void CPlayerMove::Draw()
{

}