/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "Actor.h"
///	“Gî•ñ
class CEnemy :	public CActor
{
public:
	CEnemy(std::shared_ptr<CTask> task);
	void Start();
	void Update();
	void Draw();
	
};

