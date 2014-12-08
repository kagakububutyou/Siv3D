//SnakeCopterAttack
#pragma once
#include "Actor.h"

class CSnakeCopterMove;

class CSnakeCopterAttack :public CActor
{
public:
	CSnakeCopterAttack(std::shared_ptr<CTask> task, Point pos);

	void Update();
	void Draw();
	void OnCollisionStart();
	void Finish();
	//Transform transform;	///<	���W�A�T�C�Y�A��]

	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���

private:

	std::unique_ptr<CSnakeCopterMove> move;	///	�ړ�����

	void Create();		///	����

	void Right();		///	�E�ړ�
	void Left();			///	���ړ�
	void Up();			//	/	��ړ�
	void Down();		///	���ړ�
	void RightUp();	///	�E��
	void RightDown();///	�E��
	void LeftUp();		///	����
	void LeftDown();	///	����

	Point TextureSize = Point(256, 256);		///	�摜�̃T�C�Y
	Point TexturePos;	///	�摜�̏ꏊ

	const Font font;
};