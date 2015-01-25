/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CBatteryAnimation :public CPlayerState
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

	int CutNum = 4;
	int Cut[4];

	Point TextureSize = Point(256, 256);		///	‰æ‘œ‚ÌƒTƒCƒY
	Point StopTexturePos[MOVEDIREC::DIREC];			///	‰æ‘œ‚ÌêŠ
	Point MoveTexturePos[MOVEDIREC::DIREC][4];	///	‰æ‘œ‚ÌêŠ
	Point StopTexture;				///	‰æ‘œ
	Point MoveTexture;			///	‰æ‘œ
	int GraphicChangeCounts;

public:

	CBatteryAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};