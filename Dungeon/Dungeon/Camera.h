/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include <Siv3D.hpp>
#include "Transform.h"

///	カメラ
class CCamera :public Transform
{
public:
	CCamera(Point pos, Point lookat);

	void Update();

private:
	Point upvec;					///	方向
	const static float Near;	///	見える近い範囲
	const static float Far;		///	見える遠い範囲
	const static float degree;	///	ズーム
	const static float Speed;	///	速度
};