/*

@author shinnnosuke hiratsuka
@date 2014.10.20

*/
#pragma once
#include "Actor.h"
class CMiniMap :public CActor
{
public:
	CMiniMap(std::shared_ptr<CTask> task, Float3 pos);

	void Draw();

private:

};
