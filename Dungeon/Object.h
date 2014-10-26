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

	///	Update�̑O�ɌĂ΂�����
	virtual void Start(){};

	///	�A�b�v�f�[�g
	virtual void Update(){};

	///	�`��
	virtual void Draw(){};

	enum class State
	{
		None,	///	���݂��Ȃ�
		Live,		///	���݂���
		Move,	///	�ړ�
		Attack,	///	�U��
		Hit,		///	�q�b�g
	};

	State GetState() const{ return state; }

	Transform transform;

protected:
	State state;
};