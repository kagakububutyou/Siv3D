/*

@author shinnnosuke hiratsuka
@date 2014.10.16

*/
#pragma once
#include "Actor.h"
class CStaircase:public CActor
{
public:
	CStaircase(std::shared_ptr<CTask> task, Float3 pos);

	void Draw();

private:

};