#pragma once
#include "Actor.h"
class CMiniSwitchWall3 :public CActor
{
public:
	CMiniSwitchWall3(std::shared_ptr<CTask> task, Point pos);

	void JudgmentDisplayMiniSwitchWall3();
	void Start();
	void Update();
	void Draw();

	static const int MapScale = 8;
	bool DisplayMiniSwitchWall3;

private:

};
