/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPatrollerAnimation :public CPlayerState
{
private:
	///	����
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	����

	void Texture(MOVEDIREC Direc);

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point MoveTexturePos[MOVEDIREC::DIREC];	///	�摜�̏ꏊ
	Point MoveTexture;			///	�摜

public:

	CPatrollerAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};