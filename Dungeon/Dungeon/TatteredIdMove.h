/*

@author shinnnosuke hiratsuka
@date 2014.10.21

*/
#pragma once
#include "PlayerState.h"

class CTatteredIdMove :public CPlayerState
{
private:
	void Right();		///	�E
	void Left();			///	��
	void Up();			//	/	��
	void Down();		///	��

	void Move();		///	����

	void WallCollision();

	void Stop();			///	��~
	void VelocitySpeed(const Point speed);	///	�ړ��ʐݒ�

	Point velocity;	///	�ړ���
	Point speed;		///	���x


public:

	CTatteredIdMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};