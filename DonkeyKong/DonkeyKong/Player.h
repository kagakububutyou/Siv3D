#pragma once

# include <Siv3D.hpp>


#include "OBJECT.h"


class CPlayer : public COBJECT
{
private:

	float force;

	static const float Speed;

	enum class STATE
	{
		LIVE,
		NOTE,
		JUNP,

	};

	STATE State;

public:
	CPlayer();
	~CPlayer(){};

	void Move();

	void Draw();
};

