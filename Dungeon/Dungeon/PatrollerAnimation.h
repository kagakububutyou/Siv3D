/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CPatrollerAnimation :public CPlayerState
{
private:
	///	•ûŒü
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

	MOVEDIREC Direc(Point player, Point scroll, Point enemy_pos, Point enemy_scale);		///	•ûŒü

	void Texture(MOVEDIREC Direc);

	Point TextureSize = Point(256, 256);		///	‰æ‘œ‚ÌƒTƒCƒY
	Point MoveTexturePos[MOVEDIREC::DIREC];	///	‰æ‘œ‚ÌêŠ
	Point MoveTexture;			///	‰æ‘œ

public:

	CPatrollerAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};