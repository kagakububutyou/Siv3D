#include "PlayerMove.h"
#include "CharacterController.h"
#include "Player.h"
#include "Floor.h"
#include "GameManager.h"
#include "Scroll.h"
#include "MiniMap.h"
#include "MiniMapPlayer.h"

#include "Goblin.h"
#include "MiniGoblin.h"
#include "EnemyManager.h"

CPlayerMove::CPlayerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Point(0, 0)),
speed(Point(8.0f, 8.0f))
{

}

void CPlayerMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}

void CPlayerMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		VelocitySpeed(Point(-speed.x,0));
	}
}

void CPlayerMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CPlayerMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CPlayerMove::Down()
{
	if (CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, speed.y));
	}
}

void CPlayerMove::RightUp()
{
	if (CharacterController::RightMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(speed.x, -speed.y));
	}
}

void CPlayerMove::RightDown()
{
	if (CharacterController::RightMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(speed.x, speed.y));
	}
}

void CPlayerMove::LeftUp()
{
	if (CharacterController::LeftMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(-speed.x, -speed.y));
	}
}

void CPlayerMove::LeftDown()
{
	if (CharacterController::LeftMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(-speed.x, speed.y));
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

void CPlayerMove::Update()
{
	Right(),
	Left();
	Up();
	Down();
	RightUp();
	RightDown();
	LeftUp();
	LeftDown();
	Stop();

	task->GetComponent<CMiniMapPlayer>(CGameManager::MiniPlayer, 0)->transform.Translate(Point(velocity.x / CMiniMap::MapScale, velocity.y / CMiniMap::MapScale));
	task->GetComponent<CScroll>(CGameManager::Scroll, 0)->transform.Translate(velocity);


	task->GetComponent<CGoblin>(CEnemyManager::Goblin, 0)->transform.Translate(-velocity);
	task->GetComponent<CMiniGoblin>(CEnemyManager::MiniGoblin, 0)->transform.Translate(Point(-velocity.x / CMiniMap::MapScale, -velocity.y / CMiniMap::MapScale));
	//task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.Translate(velocity);
}