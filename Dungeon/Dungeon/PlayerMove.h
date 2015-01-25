/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPlayerMove :public CPlayerState
{
private:
	void Right();		///	‰EˆÚ“®
	void Left();			///	¶ˆÚ“®
	void Up();			//	/	ãˆÚ“®
	void Down();		///	‰ºˆÚ“®
	void Stop();			///	’â~
	void VelocitySpeed(const Point speed);	///	ˆÚ“®—Êİ’è

	Point velocity;	///	ˆÚ“®—Ê
	Point speed;		///	‘¬“x

	State state;

	///	•ûŒü
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

	///	ˆÚ“®—Ê‚ğæ“¾
	Point GetVelocity()const { return velocity; }

	//MOVEDIREC GetMoveDirec() const{ return MoveDirec; }

};