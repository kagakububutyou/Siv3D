//PlayerAttack
#pragma once
#include "PlayerState.h"

class CPlayerAnimation :public CPlayerState
{
private:
	void Right();		///	�E
	void Left();			///	��
	void Up();			//	/	��
	void Down();		///	��

	

	///	����
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

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point StopTexturePos[MOVEDIREC::DIREC];			///	�摜�̏ꏊ
	Point MoveTexturePos[MOVEDIREC::DIREC][4];	///	�摜�̏ꏊ
	Point StopTexture;				///	�摜
	Point MoveTexture;			///	�摜
	int GraphicChangeCounts;

public:

	CPlayerAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};