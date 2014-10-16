/*

@author shinnnosuke hiratsuka
@date 2014.10.16

*/
#pragma once
#include "PlayerState.h"
#include "Camera.h"

class CPlayerCamera :public CPlayerState
{
public:
	CPlayerCamera(std::shared_ptr<CTask> task);

	void Update();

private:
	std::unique_ptr<CCamera> camera;	///	ƒJƒƒ‰
};