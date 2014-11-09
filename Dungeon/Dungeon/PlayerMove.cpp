#include "PlayerMove.h"
#include "CharacterController.h"
#include "Player.h"
#include "Floor.h"
#include "GameManager.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "MiniMapPlayer.h"

#include "Collision.h"

#include "Goblin.h"
#include "MiniGoblin.h"
#include "EnemyManager.h"

#include "Wall.h"
#include "MapRead.h"

CPlayerMove::CPlayerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
state(State::Live),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}
void CPlayerMove::Start()
{
	TextureAsset::Register(L"MainCharacter", L"engine/data/texture/Character/MainCharacter/shujinkoutachi.png");

	TexturePos = Point(1, 1);
}
void CPlayerMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}

void CPlayerMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		VelocitySpeed(Point(-speed.x, 0));
		TexturePos = Point(0, 1);
	}
}

void CPlayerMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		VelocitySpeed(Point(speed.x, 0));
		TexturePos = Point(2, 1);
	}
}

void CPlayerMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(0, -speed.y));
		TexturePos = Point(1, 0);
	}
}

void CPlayerMove::Down()
{
	if (CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, speed.y));
		TexturePos = Point(1, 2);
	}
}

void CPlayerMove::RightUp()
{
	if (CharacterController::RightMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(speed.x, -speed.y));
		TexturePos = Point(2, 0);
	}
}

void CPlayerMove::RightDown()
{
	if (CharacterController::RightMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(speed.x, speed.y));
		TexturePos = Point(2, 2);
	}
}

void CPlayerMove::LeftUp()
{
	if (CharacterController::LeftMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(-speed.x, -speed.y));
		TexturePos = Point(0, 0);
	}
}

void CPlayerMove::LeftDown()
{
	if (CharacterController::LeftMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(-speed.x, speed.y));
		TexturePos = Point(0, 2);
	}
}

void CPlayerMove::Stop()
{
	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey()
		&& !CharacterController::UpMoveKey() && !CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, 0));
	}
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
}
void CPlayerMove::Update()
{
	//if (state == State::None) return;
	
	Right(),
	Left();
	Up();
	Down();
	RightUp();
	RightDown();
	LeftUp();
	LeftDown();
	Stop();

	WallCollision();
		
	task->GetComponent<CMiniMapPlayer>(CGameManager::MiniPlayer, 0)->transform.Translate(Point(velocity.x / CMiniMap::MapScale, velocity.y / CMiniMap::MapScale));
	task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.Translate(velocity);

	//task->GetComponent<CGoblin>(CEnemyManager::Goblin, 0)->transform.Translate(-velocity);
	//task->GetComponent<CMiniGoblin>(CEnemyManager::MiniGoblin, 0)->transform.Translate(Point(-velocity.x / CMiniMap::MapScale, -velocity.y / CMiniMap::MapScale));
	//task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.Translate(velocity);
}
void CPlayerMove::Draw()
{
	auto player = task->GetComponent<CPlayer>(CGameManager::PlayerName, 0);

	Rect(player->transform.GetPos(), player->transform.GetScale())(TextureAsset(L"MainCharacter")(TextureSize.x * TexturePos.x, TextureSize.y * TexturePos.y, TextureSize.x, TextureSize.y)).draw();
}