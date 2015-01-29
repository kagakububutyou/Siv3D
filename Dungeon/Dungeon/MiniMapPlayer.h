/*

@author shinnnosuke hiratsuka
@date 2014.10.26

*/

#pragma once
#include "Actor.h"

class CMiniMapPlayer :public CActor
{
public:
	CMiniMapPlayer(std::shared_ptr<CTask> task, Point pos);

	void Start();		///	初めに呼ぶ関数
	void Update();		///	毎フレーム呼ぶ関数
	void Draw();		///	描画関係の関数

private:
};