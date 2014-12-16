#pragma once
#include "Actor.h"
class CSwitchWall1 : public CActor
{
public:
	CSwitchWall1(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:

};
