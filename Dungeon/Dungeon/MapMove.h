/*

@author shinnnosuke hiratsuka
@date 2014.10.23

*/
#pragma once
#include "MapState.h"

class CMapMove :public CMapState
{
public:
	CMapMove(std::shared_ptr<CTask> task);

	void Update();

	///	�ړ��ʂ��擾
	Point GetVelocity()const { return velocity; }

private:
	void Right();		///	�E�ړ�
	void Left();			///	���ړ�
	void Up();			//	/	��ړ�
	void Down();		///	���ړ�
	void RightUp();	///	�E��
	void RightDown();///	�E��
	void LeftUp();		///	����
	void LeftDown();	///	����
	void Stop();			///	��~
	void VelocitySpeed(const Point speed);	///	�ړ��ʐݒ�

	Point velocity;	///	�ړ���
	Point speed;		//	/	���x
};