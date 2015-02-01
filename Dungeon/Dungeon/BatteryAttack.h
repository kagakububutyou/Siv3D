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

	bool isCollision;	///<	あたり判定がおこっているかどうか

private:

	std::unique_ptr<CBatteryMove> move;	///	移動処理

	void Create();		///	生成
	
	///	方向
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	//void AttackPosition();
	void PosUpdate();	///	攻撃する場所
	void Position(MOVEDIREC direc);

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	方向
	Point AttackPos[MOVEDIREC::DIREC];

	const Font font;
};