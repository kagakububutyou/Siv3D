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
		task(task), state(State::Live){};

	virtual void Update() = 0;

	enum class State
	{
		None,
		Live,
	};

	State GetState()const{ return state; }

protected:
	std::shared_ptr<CTask> task;
	State state;

	///	•ûŒü
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};
};