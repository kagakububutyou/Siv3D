/*

@author shinnnosuke hiratsuka
@date 2014.11.17

*/
#pragma once
#include "Actor.h"

class CBatteryAnimation;
class CBatteryMove;
class CBatteryAttack;

class CBattery :public CActor
{
public:

	CBattery(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CBatteryAnimation> anime;	///	アニメーション
	std::unique_ptr<CBatteryMove> move;			///	移動
	std::unique_ptr<CBatteryAttack> attack;		///	攻撃

	bool isCollision;

	const Font font;

	int HP;
	int GetHP(){ return HP; };
	void HitAttack(){ HP = HP - 1; };
};