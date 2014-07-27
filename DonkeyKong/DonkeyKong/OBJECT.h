#pragma once
#include <Siv3D.hpp>
#include <memory>

/*
	基底クラス
*/

class COBJECT
{
public:
	COBJECT(){}
	~COBJECT(){}

	Float3 Pos;			//	座標
	Float3 Velocity;	//	速度
	Float3 Size;		//	大きさ
	Color color;


	virtual void Draw() = 0;	//描画

};

