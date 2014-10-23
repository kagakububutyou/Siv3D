#include "PlayerMove.h"
#include "CharacterController.h"
#include "MapMove.h"
#include "MapScroll.h"
#include "Floor.h"
#include "GameManager.h"

CMapMove::CMapMove(std::shared_ptr<CTask> task) :
CMapState(task),
velocity(Point(0, 0)),
speed(Point(2.0f, 2.0f))
{

}

void CMapMove::VelocitySpeed(const Point speed)
{
	velocity = speed;
}

void CMapMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		VelocitySpeed(Point(-speed.x, 0));
	}
}

void CMapMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		VelocitySpeed(Point(speed.x, 0));
	}
}

void CMapMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(0, -speed.y));
	}
}

void CMapMove::Down()
{
	if (CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, speed.y));
	}
}

void CMapMove::RightUp()
{
	if (CharacterController::RightMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(speed.x, -speed.y));
	}
}

void CMapMove::RightDown()
{
	if (CharacterController::RightMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(speed.x, speed.y));
	}
}

void CMapMove::LeftUp()
{
	if (CharacterController::LeftMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Point(-speed.x, -speed.y));
	}
}

void CMapMove::LeftDown()
{
	if (CharacterController::LeftMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(-speed.x, speed.y));
	}
}

void CMapMove::Stop()
{
	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey()
		&& !CharacterController::UpMoveKey() && !CharacterController::DownMoveKey())
	{
		VelocitySpeed(Point(0, 0));
	}
}

void CMapMove::Update()
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

	/*
	for (int i = 0; i < task->GetSize(CGameManager::FloorName); i++)
	{
	task->GetComponent<CFloor>(CGameManager::FloorName, i)->transform.Translate(velocity);
	}
	//*/

	task->GetComponent<CMapScroll>(CGameManager::Scroll,0)->transform.Translate(velocity);

}