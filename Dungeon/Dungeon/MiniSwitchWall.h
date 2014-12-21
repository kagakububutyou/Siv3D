#pragma once
#include "Actor.h"
class CMiniSwitchWall :public CActor
{
public:
	CMiniSwitchWall(std::shared_ptr<CTask> task, Point pos);

	void JudgmentDisplayMiniSwitchWall();
	void Start();
	void Update();
	void Draw();

	static const int MapScale = 8;
	bool DisplayMiniSwitchWall;

private:

};
