/*

@author shinnnosuke hiratsuka
@date 2014.10.21

*/
#pragma once
#include "PlayerState.h"

class CBatteryMove :public CPlayerState
{
private:


	void WallCollision();			///	�ǂƂ̓����蔻��

	void Stop();			///	��~
	void VelocitySpeed(const Point speed);	///	�ړ��ʐݒ�

	///	����
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	����
	void CollisionMoveDirec(Point player, Point object);
	Point MoveDirecData[MOVEDIREC::DIREC];
	void Move(MOVEDIREC direc);

	Point velocity;	///	�ړ���
	Point speed;		///	���x


public:

	CBatteryMove(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};