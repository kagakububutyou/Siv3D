/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Actor.h"
#include <string>

class CPlayerMove;
class CPlayerAttack;
class CPlayerAnimation;

class CPlayer :public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

	int GetMaxHP(){ return MaxHP; };
	int GetHP(){ return HP; };
	void HitAttack(){ HP = HP - 1; return; };
	void DeathCHANGEScene();

	bool behavior;

private:
	std::unique_ptr<CPlayerAnimation> anime;	///	�A�j���[�V����
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����
	std::unique_ptr<CPlayerAttack> attack;	///	�U��

	Point MiniPlayerPos;
	int HP;
	int MaxHP;
};