/*

@author shinnnosuke hiratsuka
@date 2014.10.21

*/
#pragma once
#include "PlayerState.h"

class CBatteryMove :public CPlayerState
{
private:
	void Right();		///	‰E
	void Left();			///	¶
	void Up();			//	/	ã
	void Down();		///	‰º

	void Move();		///	“®‚«

	void WallCollision();

	void Stop();			///	’â~
	void VelocitySpeed(const Point speed);	///	ˆÚ“®—Êİ’è

	Point velocity;	///	ˆÚ“®—Ê
	Point speed;		///	‘¬“x


public:

	CBatteryMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};