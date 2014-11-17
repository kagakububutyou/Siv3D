/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPatrollerMove :public CPlayerState
{
private:
	void Right();		///	右
	void Left();			///	左
	void Up();			//	/	上
	void Down();		///	下

	Point TextureSize = Point(256, 256);		///	画像のサイズ
	Point TexturePos;	///	画像の場所

public:

	CPatrollerMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};