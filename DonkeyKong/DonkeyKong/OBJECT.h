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
	Float3 Size;		//	�傫��


	virtual void Draw(Color color) = 0;	//�`��

};

