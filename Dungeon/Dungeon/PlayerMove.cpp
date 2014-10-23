#include "PlayerMove.h"
#include "CharacterController.h"
#include "Player.h"
#include "GameManager.h"

CPlayerMove::CPlayerMove(std::shared_ptr<CTask> task) :
CPlayerState(task),
velocity(Float3(0, 0, 0)),
speed(Float3(20.0f, 20.0f, 0))
{

}

void CPlayerMove::VelocitySpeed(const Float3 speed)
{
	velocity = speed;
}

void CPlayerMove::Left()
{
	if (CharacterController::LeftMoveKey())
	{
		VelocitySpeed(Float3(-speed.x,0,0));
	}
}

void CPlayerMove::Right()
{
	if (CharacterController::RightMoveKey())
	{
		VelocitySpeed(Float3(speed.x, 0, 0));
	}
}

void CPlayerMove::Up()
{
	if (CharacterController::UpMoveKey())
	{
		VelocitySpeed(Float3(0, speed.y, 0));
	}
}

void CPlayerMove::Down()
{
	if (CharacterController::DownMoveKey())
	{
		VelocitySpeed(Float3(0, -speed.y, 0));
	}
}

void CPlayerMove::RightUp()
{
	if (CharacterController::RightMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Float3(speed.x, speed.y, 0));
	}
}

void CPlayerMove::RightDown()
{
	if (CharacterController::RightMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Float3(speed.x, -speed.y, 0));
	}
}

void CPlayerMove::LeftUp()
{
	if (CharacterController::LeftMoveKey() && CharacterController::UpMoveKey())
	{
		VelocitySpeed(Float3(-speed.x, speed.y, 0));
	}
}

void CPlayerMove::LeftDown()
{
	if (CharacterController::LeftMoveKey() && CharacterController::DownMoveKey())
	{
		VelocitySpeed(Float3(-speed.x, -speed.y, 0));
	}
}

void CPlayerMove::Stop()
{
	if (!CharacterController::RightMoveKey() && !CharacterController::LeftMoveKey()
		&& !CharacterController::UpMoveKey() && !CharacterController::DownMoveKey())
	{
		VelocitySpeed(Float3(0, 0, 0));
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

	task->GetComponent<CPlayer>(CGameManager::PlayerName, 0)->transform.Translate(velocity);
}