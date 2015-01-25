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

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point TexturePos;	///	�摜�̏ꏊ
	Point MoveTexturePos;	///	�摜�̏ꏊ
	int GraphicChangeCounts;

public:

	CPlayerAnimation(std::shared_ptr<CTask> task);

	void Start();

	void Update();

	void Draw();

};