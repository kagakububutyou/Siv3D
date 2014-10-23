/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>
#include "Noncopyable.h"
#include "Transform.h"

class Object : private Noncopyable
{
public:
	enum class State;
	Object() : transform(Point(0, 0), Point(0, 0), Point(0, 0)){}
	Object(Transform transform, State state) :
		transform(transform), state(state){}
	virtual ~Object() = default;

	///	Updateの前に呼ばれるもの
	virtual void Start(){};

	///	アップデート
	virtual void Update(){};

	///	描画
	virtual void Draw(){};

	enum class State
	{
		None,	///	存在しない
		Live,		///	存在する
		Move,	///	移動
		Attack,	///	攻撃
		Hit,		///	ヒット
	};

	State GetState() const{ return state; }

	Transform transform;

protected:
	State state;
};