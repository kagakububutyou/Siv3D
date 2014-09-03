#pragma once
#include <Siv3D.hpp>
#include <memory>

/*
	���N���X
*/

class COBJECT
{
public:
	COBJECT(){}
	~COBJECT(){}

	Float3 Pos;			//	���W
	Float3 Velocity;	//	���x
	Float3 Direction;	//	����
	Float3 Size;		//	�傫��
	Color color;


	virtual void Draw() = 0;		//	�`��
	virtual void Update() = 0;	//	�A�b�v�f�[�g
	virtual void Death() = 0;	//	���S

};

