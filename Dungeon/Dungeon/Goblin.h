/*

@author shinnnosuke hiratsuka
@date 2014.10.09

*/
#pragma once
#include "Actor.h"

class CPlayerMove;

class CGoblin :public CActor
{
public:

	CGoblin(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CPlayerMove> move;	///	�ړ�����

	bool isCollision;

	const Font font;
};