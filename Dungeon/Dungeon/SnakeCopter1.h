/*

@author shinnnosuke hiratsuka
@date 2014.11.17

*/
#pragma once
#include "Actor.h"

class CSnakeCopter1Animation;
class CSnakeCopter1Move;

class CSnakeCopter1 :public CActor
{
public:

	CSnakeCopter1(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CSnakeCopter1Animation> anime;	///	アニメーション
	std::unique_ptr<CSnakeCopter1Move> move;			///	移動

	bool isCollision;

	const Font font;
};