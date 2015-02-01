/*

@author shinnnosuke hiratsuka
@date 2014.10.02

*/
#pragma once
#include "PlayerState.h"

class CBatteryAnimation :public CPlayerState
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

	int CutNum = 4;
	int Cut[4];

	Point TextureSize = Point(256, 256);		///	画像のサイズ
	Point StopTexturePos[MOVEDIREC::DIREC];			///	画像の場所
	Point MoveTexturePos[MOVEDIREC::DIREC][4];	///	画像の場所
	Point StopTexture;				///	画像
	Point MoveTexture;			///	画像
	int GraphicChangeCounts;

public:

	CBatteryAnimation(std::shared_ptr<CTask> task);

	void Start();		///	初めに呼ぶ関数

	void Update();		///	毎フレーム呼ぶ関数

	void Draw();		///	描画関係の関数

};