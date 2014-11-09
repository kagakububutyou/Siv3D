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

	void Start();

	void Update();

	void Draw();

	void WallCollision();

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
	Point speed;		///	���x

	State state;

	///	����
	enum class MOVEDIREC{
		Right,
		Left,
		Up,
		Down,
		RightUp,
		RightDown,
		LeftUp,
		LeftDown,
		Stop,
	};

	MOVEDIREC MoveDirec;

	const Point TextureSize = Point(64,85);		///	�摜�̃T�C�Y
	Point TexturePos;	///	�摜�̏ꏊ

};