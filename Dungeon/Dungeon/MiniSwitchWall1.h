#pragma once
#include "Actor.h"
class CMiniSwitchWall1 :public CActor
{
public:
	CMiniSwitchWall1(std::shared_ptr<CTask> task, Point pos);

	void JudgmentDisplayMiniSwitchWall1();
	void Start();
	void Update();
	void Draw();

	static const int MapScale = 8;
	bool DisplayMiniSwitchWall1;

private:

};
