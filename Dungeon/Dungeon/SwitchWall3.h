#pragma once
#include "Actor.h"
class CSwitchWall3 : public CActor
{
public:
	CSwitchWall3(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:

};
