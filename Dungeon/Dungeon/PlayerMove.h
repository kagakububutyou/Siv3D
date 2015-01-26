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

	void WallCollision();			///	�ǂƂ̓����蔻��
	void EnemyCollision();		///	�G�Ƃ̓����蔻��

	enum EnemyName
	{
		Patroller,
		SnakeCopter,
		TatteredId,
		Battery,

		EnemyMax,
	};

	///	����
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};
	MOVEDIREC Direc(Point player, Point enemy, Point scroll);
	void Move(MOVEDIREC direc);
	void knockBack();		///	�m�b�N�o�b�N

	Point MoveDirec[MOVEDIREC::DIREC];
	Point velocity;	///	�ړ���
	Point speed;		///	���x

	State state;

public:
	CPlayerMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

	

	///	�ړ��ʂ��擾
	Point GetVelocity()const { return velocity; }

	//MOVEDIREC GetMoveDirec() const{ return MoveDirec; }

};