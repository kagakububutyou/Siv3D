#pragma once

# include <Siv3D.hpp>


#include "OBJECT.h"


class CPlayer : public COBJECT
{
private:

	float force;

	float UseCount;
	bool DeathFlag;

	const float UseMaxCount = 600;	//	変数は横

	static const float Speed;

	enum class STATE
	{
		LIVE,
		NOTE,
		JUNP,
		HAMMER,
		DEATH,

	};

	STATE State;
	std::unique_ptr<Font> Text;

public:
	CPlayer();
	~CPlayer(){};

	//	関数は上
	void Reset();

	void Move();
	void Collision();
	void Death();
	void UseHammer();

	void Draw();
	void Update();
};

//	コピーさせないようにする
class Noncopyable
{
	Noncopyable() = default;
	Noncopyable(const Noncopyable&) = delete;
	Noncopyable& operator =(const Noncopyable&) = delete;
	
};
