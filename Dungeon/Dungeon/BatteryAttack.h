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

	bool isCollision;	///<	‚ ‚½‚è”»’è‚ª‚¨‚±‚Á‚Ä‚¢‚é‚©‚Ç‚¤‚©

private:

	std::unique_ptr<CBatteryMove> move;	///	ˆÚ“®ˆ—

	void Create();		///	¶¬
	
	///	•ûŒü
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	//void AttackPosition();
	void PosUpdate();	///	UŒ‚‚·‚éêŠ
	void Position(MOVEDIREC direc);

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	•ûŒü
	Point AttackPos[MOVEDIREC::DIREC];

	const Font font;
};