/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Actor.h"

class CPlayerMove;
class CPlayerAttack;
class CPlayerAnimation;

class CPlayer :public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();		///	���߂ɌĂԊ֐�
	void Update();		///	���t���[���ĂԊ֐�
	void Draw();		///	�`��֌W�̊֐�

	int GetMaxHP(){ return MaxHP; };
	int GetHP(){ return HP; };
	void HitAttack(){ HP = HP - 1; return; };

	bool behavior;		///	�����Ă��邩�ǂ����炵��

private:
	std::unique_ptr<CPlayerAnimation> anime;	///	�A�j���[�V����
	std::unique_ptr<CPlayerMove> move;			///	�ړ�����
	std::unique_ptr<CPlayerAttack> attack;		///	�U��

	int HP;
	int MaxHP;
};