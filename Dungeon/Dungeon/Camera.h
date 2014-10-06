/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>
#include "Transform.h"

///	�J����
class CCamera :public Transform
{
public:
	CCamera(Float3 pos, Float3 lookat);

	void Update();

private:
	Float3 upvec;					///	����
	const static float Near;	///	������߂��͈�
	const static float Far;		///	�����鉓���͈�
	const static float degree;	///	�Y�[��
	const static float Speed;	///	���x
};