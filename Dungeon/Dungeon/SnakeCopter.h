/*

@author shinnnosuke hiratsuka
@date 2014.11.17

*/
#pragma once
#include "Actor.h"

class CSnakeCopterAnimation;
class CSnakeCopterMove;

class CSnakeCopter :public CActor
{
public:

	CSnakeCopter(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CSnakeCopterAnimation> anime;	///	アニメーション
	std::unique_ptr<CSnakeCopterMove> move;			///	移動

	bool isCollision;

	const Font font;

	int HP;
	int GetHP(){ return HP; };
	void HitAttack(){ HP = HP - 1; };
};