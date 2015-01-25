/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CBatteryAnimation :public CPlayerState
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

	int CutNum = 4;
	int Cut[4];

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point StopTexturePos[MOVEDIREC::DIREC];			///	�摜�̏ꏊ
	Point MoveTexturePos[MOVEDIREC::DIREC][4];	///	�摜�̏ꏊ
	Point StopTexture;				///	�摜
	Point MoveTexture;			///	�摜
	int GraphicChangeCounts;

public:

	CBatteryAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};