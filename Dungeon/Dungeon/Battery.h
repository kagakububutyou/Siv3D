/*

@author shinnnosuke hiratsuka
@date 2014.11.17

*/
#pragma once
#include "Actor.h"

class CBatteryAnimation;
class CBatteryMove;

class CBattery :public CActor
{
public:

	CBattery(std::shared_ptr<CTask> task, Point pos);
	void Start();
	void Update();
	void Draw();

private:

	void OnCollision();

	std::unique_ptr<CBatteryAnimation> anime;	///	�A�j���[�V����
	std::unique_ptr<CBatteryMove> move;			///	�ړ�

	bool isCollision;

	const Font font;
};