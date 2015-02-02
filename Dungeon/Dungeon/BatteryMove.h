/*

@author shinnnosuke hiratsuka
@date 2014.10.21

*/
#pragma once
#include "PlayerState.h"

class CBatteryMove :public CPlayerState
{
private:


	void WallCollision();			///	•Ç‚Æ‚Ì“–‚½‚è”»’è

	void Stop();			///	’â~
	void VelocitySpeed(const Point speed);	///	ˆÚ“®—Êİ’è

	///	•ûŒü
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	•ûŒü
	void CollisionMoveDirec(Point player, Point object);
	Point MoveDirecData[MOVEDIREC::DIREC];
	void Move(MOVEDIREC direc);

	Point velocity;	///	ˆÚ“®—Ê
	Point speed;		///	‘¬“x


public:

	CBatteryMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};