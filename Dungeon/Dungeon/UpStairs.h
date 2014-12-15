/*

@author shinnnosuke hiratsuka
@date 2014.10.16

*/
#pragma once
#include "Actor.h"
class CSceneManager;

class CUpStairs :public CActor
{
public:
	CUpStairs(std::shared_ptr<CTask> task, Point pos);

	void Start();
	void Update();
	void ChangeSceneClear();
	void Draw();

	std::shared_ptr<CSceneManager> scene;

private:

};
