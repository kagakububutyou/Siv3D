//PlayerAttack
#pragma once
#include "PlayerState.h"

class CPlayerAnimation :public CPlayerState
{
private:
	void Right();		///	右
	void Left();			///	左
	void Up();			//	/	上
	void Down();		///	下

	

	///	方向
	enum  MOVEDIREC{
		LEFT,
		RIGHT,
		UP,
		DOWN,

		DIREC,
	};

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

	CPlayerAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};