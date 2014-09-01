#pragma once
#include "OBJECT.h"
class CHammer :	public COBJECT
{
private:

	enum class STATE
	{
		LIVE,
		DEATH,
	};

	STATE State;

	float UseCount;

	const float UseMaxCount = 600;

	bool IsCollisionPlayer;

public:
	CHammer();
	~CHammer(){};

	void Collision();
	void Move();
	void Draw();
	void Update();
	void Death();
};

