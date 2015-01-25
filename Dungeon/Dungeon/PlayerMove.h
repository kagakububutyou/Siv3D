/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPlayerMove :public CPlayerState
{
private:
	void Right();		///	�E�ړ�
	void Left();			///	���ړ�
	void Up();			//	/	��ړ�
	void Down();		///	���ړ�
	void Stop();			///	��~
	void VelocitySpeed(const Point speed);	///	�ړ��ʐݒ�

	Point velocity;	///	�ړ���
	Point speed;		///	���x

	State state;

	///	����
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

	///	�ړ��ʂ��擾
	Point GetVelocity()const { return velocity; }

	//MOVEDIREC GetMoveDirec() const{ return MoveDirec; }

};