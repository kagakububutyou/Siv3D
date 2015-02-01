//BatteryAttack
#pragma once
#include "Actor.h"

class CBatteryMove;

class CBatteryAttack :public CActor
{
public:
	CBatteryAttack(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();
	void OnCollisionStart();
	void Finish();

	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���

private:

	std::unique_ptr<CBatteryMove> move;	///	�ړ�����

	void Create();		///	����
	
	///	����
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	//void AttackPosition();
	void PosUpdate();	///	�U������ꏊ
	void Position(MOVEDIREC direc);

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	����
	Point AttackPos[MOVEDIREC::DIREC];

	const Font font;
};