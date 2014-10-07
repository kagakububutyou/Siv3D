#include "CharacterController.h"
#include <Siv3D.hpp>

bool CharacterController::LeftMoveKey()
{
	if (Input::KeyA.pressed) return true;
	if (Input::KeyLeft.pressed) return true;
	return false;
}

bool CharacterController::RightMoveKey()
{
	if (Input::KeyD.pressed) return true;
	if (Input::KeyRight.pressed) return true;
	return false;
}

bool CharacterController::UpMoveKey()
{
	if (Input::KeyW.pressed) return true;
	if (Input::KeyUp.pressed) return true;
	return false;
}

bool CharacterController::DownMoveKey()
{
	if (Input::KeyS.pressed) return true;
	if (Input::KeyDown.pressed) return true;
	return false;
}

bool CharacterController::ChangeSceneKey()
{
	if (Input::KeyZ.pressed) return true;
	if (Input::KeyEnter.pressed) return true;
	return false;
}