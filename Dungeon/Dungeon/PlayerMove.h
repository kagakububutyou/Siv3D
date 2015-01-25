/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPlayerMove :public CPlayerState
{
private:
	void Right();		///	右移動
	void Left();			///	左移動
	void Up();			//	/	上移動
	void Down();		///	下移動
	void Stop();			///	停止
	void VelocitySpeed(const Point speed);	///	移動量設定

	Point velocity;	///	移動量
	Point speed;		///	速度

	State state;

	///	方向
	enum  MOVEDIREC{
		RIGHT,
		LEFT,
		UP,
		DOWN,

		DIREC,
	};


public:
	CPlayerMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

	void WallCollision();

	///	移動量を取得
	Point GetVelocity()const { return velocity; }

	//MOVEDIREC GetMoveDirec() const{ return MoveDirec; }

};