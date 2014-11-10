/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/

#pragma once
#include "Actor.h"
#include <string>

class CPlayerMove;
class CPlayerAttack;

class CPlayer :public CActor
{
public:
	CPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����
	std::unique_ptr<CPlayerAttack> attack;	///	�U��

	Point MiniPlayerPos;
};