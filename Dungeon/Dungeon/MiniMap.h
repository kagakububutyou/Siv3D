/*

@author shinnnosuke hiratsuka
@date 2014.10.20

*/
#pragma once
#include "Actor.h"
class CMiniMap :public CActor
{
public:
	CMiniMap(std::shared_ptr<CTask> task, Point pos);

	void JudgmentDisplayMiniMap();
	void Start();
	void Update();
	void Draw();

	static const int MapScale = 8;
	bool DisplayMiniMap;

private:

};
