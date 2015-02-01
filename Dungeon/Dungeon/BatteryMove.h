/*

@author shinnnosuke hiratsuka
@date 2014.10.21

*/
#pragma once
#include "PlayerState.h"

class CBatteryMove :public CPlayerState
{
private:


	void WallCollision();			///	壁との当たり判定

	void Stop();			///	停止
	void VelocitySpeed(const Point speed);	///	移動量設定

	///	方向
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	方向

	Point MoveDirecData[MOVEDIREC::DIREC];
	void Move(MOVEDIREC direc);

	Point velocity;	///	移動量
	Point speed;		///	速度


public:

	CBatteryMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};