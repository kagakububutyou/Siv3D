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

	///	�ړ��ʂ��擾
	Float3 GetVelocity()const { return velocity; }

private:
	void Right();	///	�E�ړ�
	void Left();		///	���ړ�
	void Up();		//	/	��ړ�
	void Down();	///	���ړ�
	void Stop();		///	��~
	void VelocitySpeed(const Float3 speed);	///	�ړ��ʐݒ�

	Float3 velocity;	///	�ړ���
	Float3 speed;		//	/	���x

};