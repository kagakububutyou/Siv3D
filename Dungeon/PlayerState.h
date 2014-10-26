/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include <memory>
#include <Siv3D.hpp>
#include "Task.h"

class CPlayerState
{
public:
	CPlayerState(std::shared_ptr<CTask> task) :
		task(task){};

	virtual void Update() = 0;

protected:
	std::shared_ptr<CTask> task;
};