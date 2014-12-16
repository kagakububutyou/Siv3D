#pragma once
#include "Actor.h"
class CSwitchWall2 : public CActor
{
public:
	CSwitchWall2(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:

};
