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

	void Start();		///	初めに呼ぶ関数
	void Update();		///	毎フレーム呼ぶ関数
	void Draw();		///	描画関係の関数

	int GetMaxHP(){ return MaxHP; };
	int GetHP(){ return HP; };
	void HitAttack(){ HP = HP - 1; return; };

	bool behavior;		///	動いているかどうからしい

private:
	std::unique_ptr<CPlayerAnimation> anime;	///	アニメーション
	std::unique_ptr<CPlayerMove> move;			///	移動処理
	std::unique_ptr<CPlayerAttack> attack;		///	攻撃

	int HP;
	int MaxHP;
};