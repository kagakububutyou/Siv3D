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

	void Start();		///	���߂ɌĂԊ֐�
	void Update();		///	���t���[���ĂԊ֐�
	void Draw();		///	�`��֌W�̊֐�

private:
};