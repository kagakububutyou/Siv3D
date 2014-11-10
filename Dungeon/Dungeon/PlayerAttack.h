//PlayerAttack
#pragma once
#include "PlayerState.h"
#include "Transform.h"

class CPlayerMove;

class CPlayerAttack :public CActor
{
public:
	CPlayerAttack(std::shared_ptr<CTask> task);

	void Update();
	void Draw();
	void OnCollisionStart();
	void Finish();
	//Transform transform;	///<	���W�A�T�C�Y�A��]

private:
	
	std::unique_ptr<CPlayerMove> move;	///	�ړ�����

	void Create();		///	����

	void Right();		///	�E�ړ�
	void Left();			///	���ړ�
	void Up();			//	/	��ړ�
	void Down();		///	���ړ�
	void RightUp();	///	�E��
	void RightDown();///	�E��
	void LeftUp();		///	����
	void LeftDown();	///	����

	bool isCollision;	///<	�����蔻�肪�������Ă��邩�ǂ���

	const Font font;
};