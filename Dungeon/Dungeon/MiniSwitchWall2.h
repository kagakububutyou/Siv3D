#pragma once
#include "Actor.h"
class CMiniSwitchWall2 :public CActor
{
public:
	CMiniSwitchWall2(std::shared_ptr<CTask> task, Point pos);

	void JudgmentDisplayMiniSwitchWall2();
	void Start();
	void Update();
	void Draw();

	static const int MapScale = 8;
	bool DisplayMiniSwitchWall2;

private:

};
