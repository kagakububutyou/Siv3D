/*

@author shinnnosuke hiratsuka
@date 2014.11.17

*/
#pragma once
#include "Actor.h"

class CTatteredIdAnimation;
class CTatteredIdMove;

class CTatteredId :public CActor
{
public:

	CTatteredId(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CTatteredIdAnimation> anime;	///	アニメーション
	std::unique_ptr<CTatteredIdMove> move;			///	移動

	bool isCollision;

	const Font font;

	int HP;
	int GetHP(){ return HP; };
	void HitAttack(){ HP = HP - 1; };
};