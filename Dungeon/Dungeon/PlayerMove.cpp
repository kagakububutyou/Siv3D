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
speed(Point(8.0f, 8.0f))
{

}
void CPlayerMove::Start()
{
	MoveDirec[MOVEDIREC::LEFT] = Point(-speed.x, 0);
	MoveDirec[MOVEDIREC::RIGHT] = Point(speed.x, 0);
	MoveDirec[MOVEDIREC::UP] = Point(0, -speed.y);
	MoveDirec[MOVEDIREC::DOWN] = Point(0, speed.y);

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
		VelocitySpeed(Point(0, speed.y));

		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
		task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->HitAttack();
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
	VelocitySpeed(MoveDirec[direc]);

	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->behavior = true;
	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->HitAttack();
}

void CPlayerMove::WallCollision()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	for (auto& floor : task->GetActor(CGameManager::WallName))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			floor->transform.GetPos() - pos, floor->transform.GetScale()))
		{
			if (player->transform.GetPos().y > floor->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (floor->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > floor->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (floor->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall : task->GetActor(CGameManager::SwitchWall))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			wall->transform.GetPos() - pos, wall->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack,0)->isEnemy1)
		{
			if (player->transform.GetPos().y > wall->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > wall->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall1 : task->GetActor(CGameManager::SwitchWall1))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			wall1->transform.GetPos() - pos, wall1->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy2)
		{
			if (player->transform.GetPos().y > wall1->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall1->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > wall1->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall1->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall2 : task->GetActor(CGameManager::SwitchWall2))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			wall2->transform.GetPos() - pos, wall2->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy3)
		{
			if (player->transform.GetPos().y > wall2->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall2->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > wall2->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall2->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
	for (auto& wall3 : task->GetActor(CGameManager::SwitchWall3))
	{
		if (Collision::RectToRect(player->transform.GetPos(), player->transform.GetScale(),
			wall3->transform.GetPos() - pos, wall3->transform.GetScale())
			&& !task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isEnemy4)
		{
			if (player->transform.GetPos().y > wall3->transform.GetPos().y - pos.y)
			{
				VelocitySpeed(Point(0, speed.y));
			}
			if (wall3->transform.GetPos().y - pos.y > player->transform.GetPos().y)
			{
				VelocitySpeed(Point(0, -speed.y));
			}
			if (player->transform.GetPos().x > wall3->transform.GetPos().x - pos.x)
			{
				VelocitySpeed(Point(speed.x, 0));
			}
			if (wall3->transform.GetPos().x - pos.x > player->transform.GetPos().x)
			{
				VelocitySpeed(Point(-speed.x, 0));
			}
		}
	}
}
void CPlayerMove::knockBack()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);
	auto pos = (task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.GetPos());

	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isHit1)
	{
		auto patroller = task->GetComponent<CPatroller>(CEnemyManager::Patroller, 0);
		if (player->transform.GetPos().x < patroller->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(-speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().x > patroller->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().y < patroller->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, -speed.y * 4));
			return;
		}
		if (player->transform.GetPos().y > patroller->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, speed.y * 4));
			return;
		}
	}
	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isHit2)
	{
		auto s = task->GetComponent<CSnakeCopter>(CEnemyManager::SnakeCopter, 0);
		if (player->transform.GetPos().x < s->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(-speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().x > s->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().y < s->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, -speed.y * 4));
			return;
		}
		if (player->transform.GetPos().y > s->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, speed.y * 4));
			return;
		}
	}
	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isHit3)
	{
		auto s1 = task->GetComponent<CTatteredId>(CEnemyManager::TatteredId, 0);
		if (player->transform.GetPos().x < s1->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(-speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().x > s1->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().y < s1->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, -speed.y * 4));
			return;
		}
		if (player->transform.GetPos().y > s1->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, speed.y * 4));
			return;
		}
	}
	if (task->GetComponent<CPlayerAttack>(CGameManager::Attack, 0)->isHit4)
	{
		auto b = task->GetComponent<CBattery>(CEnemyManager::Battery, 0);
		if (player->transform.GetPos().x < b->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(-speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().x > b->transform.GetPos().x - pos.x)
		{
			VelocitySpeed(Point(speed.x * 4, 0));
			return;
		}
		if (player->transform.GetPos().y < b->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, -speed.y * 4));
			return;
		}
		if (player->transform.GetPos().y > b->transform.GetPos().y - pos.y)
		{
			VelocitySpeed(Point(0, speed.y * 4));
			return;
		}
	}
	//*/
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