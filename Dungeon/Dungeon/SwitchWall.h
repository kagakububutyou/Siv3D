#pragma once
#include "Actor.h"
class CSwitchWall : public CActor
{
public:
	CSwitchWall(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void Draw();

private:

};
