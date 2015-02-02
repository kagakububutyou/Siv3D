/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPatrollerAnimation :public CPlayerState
{
private:
	///	方向
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	方向

	void Texture(MOVEDIREC Direc);

	Point TextureSize = Point(256, 256);		///	画像のサイズ
	Point MoveTexturePos[MOVEDIREC::DIREC];	///	画像の場所
	Point MoveTexture;			///	画像

public:

	CPatrollerAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};