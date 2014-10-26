/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPlayerMove :public CPlayerState
{
public:
	CPlayerMove(std::shared_ptr<CTask> task);

	void Update();

	///	移動量を取得
	Point GetVelocity()const { return velocity; }

private:
	void Right();		///	右移動
	void Left();			///	左移動
	void Up();			//	/	上移動
	void Down();		///	下移動
	void RightUp();	///	右上
	void RightDown();///	右下
	void LeftUp();		///	左上
	void LeftDown();	///	左下
	void Stop();			///	停止
	void VelocitySpeed(const Point speed);	///	移動量設定

	Point velocity;	///	移動量
	Point speed;		//	/	速度

};