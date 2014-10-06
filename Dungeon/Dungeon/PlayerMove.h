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

	///	ˆÚ“®—Ê‚ğæ“¾
	Float3 GetVelocity()const { return velocity; }

private:
	void Right();	///	‰EˆÚ“®
	void Left();		///	¶ˆÚ“®
	void Up();		//	/	ãˆÚ“®
	void Down();	///	‰ºˆÚ“®
	void Stop();		///	’â~
	void VelocitySpeed(const Float3 speed);	///	ˆÚ“®—Êİ’è

	Float3 velocity;	///	ˆÚ“®—Ê
	Float3 speed;		//	/	‘¬“x

};